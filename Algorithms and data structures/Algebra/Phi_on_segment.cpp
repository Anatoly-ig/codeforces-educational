const int max_n = 100;
vector<int> fi_prime(max_n, -1);
vector<int> phi(max_n, -1);

void precalc()
{
    for (ll i = 2; i * i < max_n; ++i)
    {
        if (fi_prime[i] == -1)
        {
            for (ll j = i * i; j < max_n; j += i)
            {
                if (fi_prime[j] == -1) fi_prime[j] = i;
            }
        }
    }
    for (ll i = 2; i < max_n; ++i)
    {
        if (fi_prime[i] == -1) fi_prime[i] = i;
    }
    phi[1] = 1;
    for (ll i = 2; i < max_n; ++i)
    {
        ll tmp = fi_prime[i];
        ll prev = i / tmp;
        phi[i] = phi[prev];
        if (fi_prime[prev] == fi_prime[i])
            phi[i] *= fi_prime[i];
        else
            phi[i] *= (fi_prime[i] - 1);
    }
}