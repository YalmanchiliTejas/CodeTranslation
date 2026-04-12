#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back


using namespace std;

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {std::cout << x;}
void __print(unsigned x) {std::cout << x;}
void __print(unsigned long x) {std::cout << x;}
void __print(unsigned long long x) {std::cout << x;}
void __print(float x) {std::cout << x;}
void __print(double x) {std::cout << x;}
void __print(long double x) {std::cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
template <typename T> inline void inp(T &any) {cin >> any;} template <typename T, typename... U>inline void inp(T &a, U &...b) {cin >> a; inp(b...);}
#define rin(args...) ll args; inp(args);
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#define matdeb(mat,row,col) cout << #mat << "::" << endl; printmat(mat,row,col); printpartition;
#define debugv(v,n) cout << #v << ":" << endl; printv(v,0,n-1); printpartition;
#else
#define debug(x...)
#define matdeb(mat,row,col)
#define debugv(v,n)
#endif

const int maxm = 1000000000 + 7;

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}


//----------->CODE BEGINS --------------->


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n,y,z;

	cin>>n>>y>>z;

	n -= z;

	cout<<n/(y+z)<<endl;

}
