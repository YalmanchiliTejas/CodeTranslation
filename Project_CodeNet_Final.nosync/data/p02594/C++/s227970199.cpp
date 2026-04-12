#include<bits/stdc++.h>

#define zton(i,n) for(int i=0;i<=n;i++)
#define oneton(i,n) for(int i=1;i<=n;i++)
#define fo(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<b;i++)
#define loop(i,b,a) for(int i=a;i>=b;i--)
#define dsort(arr,n) sort(arr, arr + n, greater<int>())
#define vsortd(a) sort(a.begin(), a.end(), greater<double>())
#define vsort(a) sort(a.begin(), a.end())
#define ll long long int
#define test int tc;cin>>tc;while(tc--)
#define dbg(x) cout<<#x<<'='<<(x)<<endl;
#define dbg2(x,y) cout<<#x<<'='<<(x)<<endl<<#y<<'='<<(y)<<endl;
#define dbg3(x,y,z) cout<<#x<<'='<<(x)<<endl<<#y<<'='<<(y)<<endl<<#z<<"="<<(z)<<endl;
#define dbg4(x,y,z,w) cout<<#x<<'='<<(x)<<endl<<#y<<'='<<(y)<<endl<<#z<<"="<<(z)<<endl<<#w<<"="<<(w);
#define minheap priority_queue <int, vector<int>, greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pb push_back
#define ff first
#define ss second
#define mpr make_pair
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mkv vector<int>
#define allzero(dp) memset(dp,0,sizeof(dp))
#define endl "\n"
#define print(x) cout<<x<<endl;

const int mod=1e9+7;
using namespace std;
bool sortcol( const vector<int>& v1,const vector<int>& v2 ) {return v1[1] < v2[1];}

void fastio()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool sortbysecdesc(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if(a.first>b.first)return true;
    if(a.first==b.first)return a.second<b.second;
    return false;
}

ll power(ll x, ll y){
    ll res = 1;x=x%mod;
    while(y>0){
        if(y&1)res=(res*x)%mod;
        y=y>>1;x=(x*x)%mod;}
    return res;
}


void solve()
{
    int x;cin>>x;
    if(x>=30)print("Yes")
    else print("No")
}

int main()
{
  //  fastio();
 //   test
    solve();
}
