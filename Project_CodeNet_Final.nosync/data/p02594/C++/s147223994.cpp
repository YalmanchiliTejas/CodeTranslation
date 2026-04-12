    #include<iostream>
    #include<algorithm>
    #include<cstdio>
    #include<cmath>
    #include<cstring>
    #include<vector>
    #include<list>
    #include<map>
    #define endl "\n"
    #define eb emplace_back
    #define FOR(i, a, b) for(long long i = a; i < b; ++i)
    #define FORR(n) for(long long i = n - 1; i >= 0; --i)
    #define FORE(n) for(const auto &i : n)
    #define MS(n, i) memset(n, i, sizeof(n))
    typedef long long ll;
    inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
    inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
    using namespace std;
    
    /*
    bool desc(pair<ll, ll> a, pair<ll, ll> b)
    {
        return b.second > a.second;
    }
    
    ll total(string a)
    {
        int len = a.size();
        ll s = 0;
        FOR(i, 0, len)
        {
            s += a[i];
        }
        return s;
    }
    void SeivePrime(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for(int p = 2; p * p <= n; p++)
        {
            if(prime[p])
            {
                for(int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }
    */

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t = 1;
        //cin >> t;
        while (t--)
        {
            int x;
            cin >> x;
            if(x >= 30)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }


/*
input:
6
7
abacaba
7
???????
11
aba?abacaba
11
abacaba?aba
15
asdf???f???qwer
11
abacabacaba

output:
Yes
abacaba
Yes
abacaba
Yes
abadabacaba
Yes
abacabadaba
No
No
*/