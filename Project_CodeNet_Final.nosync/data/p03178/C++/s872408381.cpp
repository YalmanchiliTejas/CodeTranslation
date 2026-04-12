//! 尺卂乃卂.卂ﾌ乇乇ㄒ
#include<bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
//Using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Ordered_set;

#define ll              long long
#define int             long long
#define ld             long double
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<vi>
#define vip            vector<pii>
#define mii             map<int,int>
#define mip             map<pair<int,int>,int>
#define mic             map<char,int> 
#define all(v)          v.begin(),v.end()  
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define lb(x)           (x&(-x))
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define itr(it,v)          for(auto it:v)
#define show(arr,n)     for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"\n";
#define fi(i,n)         for(int i=0;i<n;i++)
#define fir(i,k,n)       for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ff               first 
#define ss               second
#define deb(x) cout << #x << "=" << x << endl
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define check(x) (x && cout<<"Yes\n")||(cout<<"No\n");
#define fin(s)          freopen(s,"r",stdin);  
#define fout(s)         freopen(s,"w",stdout);

const ld pi = 3.141592653589793238462643383279502884;
const int xd[]={-1,0,1,0};
const int yd[]={0,-1,0,1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0,  1, -1, 1, -1, 0, 1 };

int expo(int a,int b,int m);
int mmi(int a,int m);
void ipgraph(int m);

const int N=5*(1e5)+10;
vii adj(N);
int a[N];
int num;
vi v;
int dp[10001][2][101];
int func(int d,int ok,int sum){
    if(d==v.size()){
        if(sum%num==0) return 1;
        else return 0;
    }
    if(dp[d][ok][sum]!=-1) return dp[d][ok][sum];
    int res=0;
    for(int i=0;i<=(ok?v[d]:9);i++){
        if(i==v[d]) res=(res+func(d+1,ok,(sum+i)%num))%mod;
        else res=(res+func(d+1,0,(sum+i)%num))%mod;
    }
    dp[d][ok][sum]=res;
    return res;
    // return 0;
}
int solve(string k){
    v.clear();
    for(auto it:k) v.pb(it-'0');
    memset(dp,-1,sizeof(dp));
    return (func(0,1,0)-1+mod)%mod;
}
int32_t main()
{
    FIO
    string k;  
    cin>>k>>num;
    cout<<solve(k)%mod<<"\n";
    return 0;

}

void ipgraph(int m){
    int i, u, v;
    while(m--){
          cin>>u>>v;
         u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
    }
}
int expo(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return a;
    int val=(expo(a,b/2,m)*expo(a,b/2,m))%m;
    if(b & 1) return (val*a)%m;
    else return val;
}
int mmi(int a,int m){
    return expo(a,m-2,m);
}