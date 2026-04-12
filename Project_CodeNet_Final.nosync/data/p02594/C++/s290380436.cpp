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
typedef vector<int> vi;
typedef pair<int,int> vii;
bool secdes(const pair<int,int>&a , const pair<int,int>&b){if(a.se==b.se){return a.fi>b.fi;}else{return a.se>b.se;}}//second descending !
bool sir(const pair<int,int>&a , const pair<int,int>&b){if(a.fi==b.fi){return a.se>b.se;}else{return a.first>b.first;}}//first descending !
bool bysec(const pair<int,int>&a , const pair<int,int>&b){if(a.se==b.se){return a.fi<b.fi;} else{return a.se<b.se;}}//second ascending !

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

const int no=3e6+5;
const int modulo=1e9+7;
const int inf=1e18+9;
const int N=1001;
int a[no]={},b[no]={},cc[no]={},suma[no]={},mat[N][N]={{0}};
stack<int> S;
stack<int> ma;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int poww(int x, int y, int modulo) {x %= modulo;int res=1;while (y > 0) {if (y & 1){res = res * x % modulo;}x = x * x % modulo;y >>= 1;}return res;}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int n=0,m=0,q=0,x=0,w=0,y=0,z=0,t=1;
void solve(){
    cin>>n;
    if(n>=30) cout<<"Yes"<<en;
    else cout<<"No"<<en;
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
    //cin>>t;q=t;
    while(t--){
        solve();
    }
}
