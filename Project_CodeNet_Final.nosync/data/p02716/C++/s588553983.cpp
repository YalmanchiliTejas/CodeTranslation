#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second



using namespace __gnu_pbds;
using namespace std;
 const int mod=1e9+7;
// const int mod=998244353;
const int INF=4e18+10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define readv(x, n) vector<int> x(n); for(auto &i:x) cin>>i; 


int pow(int a, int b)
{
    int prod=1;
    int mult=a%mod;
    while(b!=0)
    {
        if(b%2)
        {
            prod*=mult;
            prod%=mod;
        }
        mult*=mult;
        mult%=mod;
        b/=2;
    }
    return prod;
}
int mod_inv(int q, int mod)
{
    return pow(q, mod-2);
}
const int MAXN=2e5;
std::vector <int> prime;
bool is_composite[MAXN];
int phi[MAXN];

void sieve (int n) {
    std::fill (is_composite, is_composite + n, false);
    phi[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            prime.push_back (i);
            phi[i] = - 1;                 //i is prime
        }
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = 0;  //prime[j] divides i
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]]; //prime[j] does not divide i
            }
        }
    }
}

signed main()

{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);  
       cout.tie(NULL);
     #ifndef ONLINE_JUDGE
        if(fopen("INPUT.txt","r"))
        {
        freopen ("INPUT.txt" , "r" , stdin);
        freopen ("OUTPUT.txt" , "w" , stdout);
        }
     #endif
    auto clk=clock(); 
    // -------------------------------------Code starts here---------------------------------------------------------------------     
 
    int n;
    cin>>n;
    readv(a,n);


    vector<int> sasti_dp(n+10, -INF);

    vector<int> dp(n+10, -INF);
    dp[0]=a[0];
    dp[1]=max(a[0], a[1]);

    sasti_dp[0]=0;

    int alter_sum=a[0];
    for(int i=2;i<n;i++)
    {
        if(i%2==0)
        {
        sasti_dp[i]=max(sasti_dp[i-2] +a[i], dp[i-1] );
        dp[i]=max(dp[i-1], sasti_dp[i-2]+a[i]);
        alter_sum+=a[i];
        }
        else
        {
            dp[i]=max(alter_sum, a[i]+ dp[i-2]);
        }

    }
    cout<<dp[n-1]<<endl;

    // -------------------------------------Code ends here------------------------------------------------------------------


    clk = clock() - clk;
    cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
 }
