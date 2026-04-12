#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define loop(i,a,b) for(int i=a;i>=b;i--)
#define forr(x,arr) for(auto& x:arr)
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-7
#define sz(x) ((lli)(x).size())
#define endl '\n'

#ifdef SANJU
    #define localsys 1
#else
    #define localsys 0
#endif

using   lli     =   long long;
using   lld     =   long double;
using   ulli    =   unsigned long long int;
using   pll     =   pair<lli, lli>;
using   ttt     =   pair<lli, pll>;
using   vttt    =   vector<ttt>;
using   vll     =   vector<pll>;
using   vl      =   vector<lli>;
using   vi      =   vector<int>;
using   vvi     =   vector<vector<int>>;
using   cd      =   complex<lld>;

void sanjeev(int kkkk)
{
    int n;
    cin>>n;
    vector<int>A;
    A.push_back(0);
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        A.push_back(t);
    }

    long long int dp[n+1][n+1]={0};

    for(int i=n;i>0;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(i==j)dp[i][j]=A[i];
            else
            {
                dp[i][j]=max(A[i]-dp[i+1][j],A[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[1][n];

}

int main()
{
    if(!localsys) ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout << fixed << setprecision(10);
    int t=1;
    //cin>>t;
    fol(i,0,t) { sanjeev(i+1); }
    if(localsys) system("pause");
}
