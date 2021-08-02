#include <bits/stdc++.h>

namespace SparseTable
{
	const int MAX_N = int(2e5 + 10);

	constexpr int highest_bit(int x);

#ifdef __GNUC__
	constexpr int highest_bit(int x)
	{
		return std::__lg(x);
	}
#else
	constexpr int highest_bit(int x)
	{
		assert(x > 0 && "X must be non zero\n");
		int cnt = -1;
		while (x)
		{
			++cnt;
			x >>= 1;
		}
		return cnt;
	}
#endif


	constexpr int MAX_BIT = highest_bit(MAX_N) + 1;

	template<class T>
	class SparseTable
	{
		int n;
		T data[MAX_BIT][MAX_N];
		T(*func)(T x, T y);
	public:
		void build(vector<T> &vec, T(*f)(T, T))
		{
			n = vec.size();
			func = f;
			for (int i = 0; i < n; ++i) data[0][i] = vec[i];

			for (int p = 1; p < MAX_BIT; ++p)
				for (int i = 0; (i + (1 << p)) <= n; ++i)
					data[p][i] = func(data[p - 1][i], data[p - 1][i + (1 << (p - 1))]);
		}

		T get(int l, int r)
		{
			int power = highest_bit(r - l + 1);
			T arg1 = data[power][l];
			T arg2 = data[power][r - (1 << power) + 1];
			return func(arg1, arg2);
		}
	};
}