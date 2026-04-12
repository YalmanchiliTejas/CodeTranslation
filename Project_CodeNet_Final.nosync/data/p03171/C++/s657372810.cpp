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

void  solve(){

}
int dp[3001][3001];
int func(int i,int j,int n){
    int ele=n-(j-i+1);
    if(i==j) {
        if(ele & 1) return 0;
        else return a[i];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans;
    if(ele & 1){
        ans=(min(func(i+1,j,n),func(i,j-1,n)));
    }
    else{
        ans=max(a[i]+func(i+1,j,n),a[j]+func(i,j-1,n));
    }
    return dp[i][j]=ans;
}
int32_t main()
{
    FIO
    int n; cin>>n;
    int s=0;
    fi(i,n) {
        cin>>a[i];
        s+=a[i];
    }
    fi(i,n+1) fi(j,n+1) dp[i][j]=-1;
    cout<<2*func(0,n-1,n)-s<<"\n";
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