#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)    for (int i = (int)b; i < (int)e; i++)
#define forr(i, b, e)    for (int i = (int)b; i < (int)e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 3341
int N,S;
int dp[tam][tam];
int v[tam];
const int MOD=998244353;
int f(int pos,int s)
{
    if (s==0)
        return (N-pos+1);
    if (s<0)
        return 0;
    if (pos==N)
        return 0;
    if (dp[pos][s]!=-1)
        return dp[pos][s];

    ll tot=0;
    tot+=f(pos+1,s-v[pos]);
    tot%=MOD;
    tot+=f(pos+1,s);tot%=MOD;
    return dp[pos][s]=tot;
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    cin>>N>>S;
    forr(i,0,N)
        cin>>v[i];
    memset(dp,-1,sizeof dp);
    ll tot=0;
    forr(i,0,N)
    {
        tot+=f(i+1,S-v[i])*(ll)(i+1);
        tot%=MOD;
    }
    cout<<tot<<endl;
}
// PLUS ULTRA!
