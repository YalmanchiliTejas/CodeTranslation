
// Problem : A - Station and Bus
// Contest : AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

/*/ Author:Amar1503/*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#define fio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ull unsigned long long
#define ll long long
#define inf INT_MAX
#define mninf INT_MIN
#define Mod 1000000007
#define endl "\n"
#define cp(x) cout<<(x)<<" "
#define cl(x) cout<<(x)<<endl
#define ct(x,y) cout<<(x)<<" "<<(y)<<endl;
#define nl   cout<<endl
//const double PI=3.1415926535897932384626433832;
//looping
#define For(i,a,b) for(int i=a;i<b;i++)
#define test(t)  int (t); cin>>(t); while((t)--)
#define array(a,n) int (n); cin>>(n); int a[n]; for(int i=0;i<(n);i++) cin>>a[i];
#define trace(x) clog<<#x<<": "<<x<<" "<<endl
#define trace2(x,y) clog<<#x<<": "<<x<<"     "<<#y<<" "<<y<<endl
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define printa(a,n) for(int i = 0 ; i < n ; i++) cout<<a[i]<<' '
#define printv(v)  for(int i=0;i<(v).size();i++) cout<<v[i]<<" "
//containers
#define F first
#define S second
#define pb emplace_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define itr(it, a) for(auto it = (a).begin(); it != (a).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ers(v)   sort(all(v)); (v).erase(unique(all(v)),(v).end())
#define printmatrix(a,n,m) for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;}
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
typedef pair <int, int> pii;
typedef vector < pair <int, int> > vpii;
// cout<<"\nTime Elapsed : " << 1.0*clock() /CLOCKS_PER_SEC << " s\n";
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,0,-1,1,-1,0,1,-1};
//#define int long long
/*/----------------------------Code begins----------------------------------/*/
int32_t main(){
fio;
string s;
cin>>s;
map<char,int> m;
For(i,0,s.size())
m[s[i]]++;
if(m.size()!=1)
cout<<"Yes";
else cout<<"No";


}







