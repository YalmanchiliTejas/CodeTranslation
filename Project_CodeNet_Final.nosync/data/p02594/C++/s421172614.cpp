#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define loop(i,a,b) for(int i=a;i<b;i++)
#define scnarr(arr, n) for (int i = 0; i < n; ++i) cin >> arr[i]
#define vi vector<int>
#define si set<int>
#define pii pair <int, int>
#define sii set<pii>
#define vii vector<pii>
#define mii map <int, int>

//Constants
const int MOD = 1000000007; /* 1e9 + 7*/
const int MAXN = 1000005; /*1e6 +5 */


int spf[1000009]; // stores the smallest prime factor of a number

void sieve()
{
spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x,  int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

void solve()
{
    int x;cin>>x;
    if(x>=30)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int32_t main()
{
   // faster;
    /*sieve();
    int t;cin>>t;
    while(t--)*/
        solve();

    return 0;
}
