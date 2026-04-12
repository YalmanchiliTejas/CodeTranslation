// Shinchan Loves Coding :)))
#include<bits/stdc++.h>
#include<map>
#include<set>
#include<stack>
using namespace std;

#define night_rider ios::sync_with_stdio(false);cin.tie(NULL);
#define int long long int
#define double long double
#define en "\n"
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define toUpper(x) transform(x.begin(), x.end(), x.begin(),::toupper);
#define toLower(x) transform(x.begin(), x.end(), x.begin(),::tolower);
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> pii;
bool secdes(const pair<int,int>&a , const pair<int,int>&b){if(a.se==b.se){return a.fi>b.fi;}else{return a.se>b.se;}}//second descending !
bool sir(const pair<int,int>&a , const pair<int,int>&b){if(a.fi==b.fi){return a.se>b.se;}else{return a.first>b.first;}}//first descending !
bool bysec(const pair<int,int>&a , const pair<int,int>&b){if(a.se==b.se){return a.fi<b.fi;} else{return a.se<b.se;}}//second ascending !

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

const int no=3e6+5;
const int modulo=1e9+7;
const int inf=1e18;
const int N=1001;
int a[no],b[no],cc[no],dd[no],mat[N][N];
stack<int> S;
stack<int> ma;
int dx[]={-1 , 0 , 1 , 0};
int dy[]={0 , 1 , 0 , -1};
char c[N][N];

//--------------------------------------------------------------------------------------------------------------------------------------------------------------
int mul(int x , int y , int mod) {
    return ((x%mod)*(y%mod))%mod;
}

int powwmod(int x, int y , int mod) { int res=1; while (y) { if (y & 1){ y--; res=mul(res,x,mod); res%=mod; } else { y/=2; x=mul(x,x,mod); x%=mod; } } return res%mod; }

int poww(int x , int y) { int res=1; while(y) { if(y%2) { y--; res=res*x; } else { y/=2; x=x*x; } } return res; }

int div(int x , int y , int mod) {
    return x*poww(y,mod-2)%mod ;
}

bool comp(int x, int y) {
    return (x < y);   // MINIMUM
    return (x > y);   // MAXIMUM
}

int gcd(int x, int y) { if(y==0) return x; else return gcd(y,x%y); }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

pii adj[no];
int dist[no];

void solve (){
    int n,m,k=0,x,y,z,p,q;
    cin>>n;
    for(int i=0 ; i<n ; i++) {cin>>a[i];k+=a[i];k%=modulo;}
    int prev=0;
    int ans=0;
    for(int i=0 ; i<n ; i++) {
        ans+=((((k-(prev+a[i]))%modulo+modulo)%modulo*a[i])%modulo);
        prev+=a[i];
        prev=prev%modulo;
    }
    cout<<ans%modulo<<en;
}

void runn(){
        #ifndef ONLINE JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
}

signed main()
{
    night_rider
    //runn();
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}
