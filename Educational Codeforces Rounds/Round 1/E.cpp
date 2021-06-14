#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using ll = long long;

int dp[31][31][51];

template<typename T> T min(const T& a, const T& b) { return (a < b) ? a : b; }

int solve(int n, int m, int k)
{
	if (dp[n][m][k] || n * m == k || !k) return dp[n][m][k];
	int res = (int)1e9;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j <= k; ++j)
			res = min(res, m * m + solve(i, m, k - j) + solve(n - i, m, j));
	for (int i = 1; i < m; ++i)
		for (int j = 0; j <= k; ++j)
			res = min(res, n * n + solve(n, i, k - j) + solve(n, m - i, j));
	return dp[n][m][k] = res;
}

int main()
{
	for (int i = 0; i < 31; ++i)
		for (int j = 0; j < 31; ++j)
			for (int k = 0; k < 51; ++k)
				dp[i][j][k] = 0;
	int t;
	int n, m, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		solve(n, m, k);
		cout << dp[n][m][k] << endl;
	}
	return 0;
}