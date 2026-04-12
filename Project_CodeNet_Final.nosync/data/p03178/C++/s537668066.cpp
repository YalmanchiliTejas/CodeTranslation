#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 100000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define vll vector<lli>
#define eps 0.000001
#define endl '\n'
#define mo 998244353
 
using namespace std ;
 
#define N 200000 + 5 

typedef tree<lli,null_type,less<lli>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

vll num;
lli d;
lli dp[10000 + 5][101][2];

lli fun(lli pos, lli sum, bool f)
{
    if(pos == num.size())
    {
        if(sum == 0) return 1;
        return 0;
    }

    if(dp[pos][sum][f] != -1) return dp[pos][sum][f];
    
    lli res = 0;
    lli LMT;

    if(!f) LMT = num[pos];

    else LMT=9;

    for(lli dgt = 0; dgt<=LMT; dgt++)
    {
        bool nf = f;
        lli nsum = sum;
        if(f == 0 && dgt < LMT) nf = 1; 
        nsum = (nsum+dgt)%d;
        res += fun(pos+1, nsum, nf);
        res%=mod;
    }

    return dp[pos][sum][f] = res;
}

int main()
{

    string k;
    cin>>k;

    cin>>d;

    loopl(i,0,k.size()) num.pb(k[i]-'0');
    memset(dp,-1,sizeof(dp));

    cout<<(fun(0,0,0)-1+mod)%mod<<endl;




}