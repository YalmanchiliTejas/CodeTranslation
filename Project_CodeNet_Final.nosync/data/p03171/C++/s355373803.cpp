#include <bits/stdc++.h>
using namespace std;

#define ld			long double
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define MOD         1000000007
#define sd(t) 		scanf("%d",&(t))
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define hii 		cout << "hii" << endl
#define okay 		cout << "okay" << endl
#define hey 		cout << "hey" << endl

template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; } 
 
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

clock_t time_p=clock();
void starboy1299()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

const int N = 3e3+5;
int dp[N][N][2];
int arr[105];
int n;
int f(int i, int j, int par){
	if(i > j) return 0;

	if(dp[i][j][par]!=-1) return dp[i][j][par];

	if(par==0){
		int op1 = arr[i] + f(i+1, j, 1-par);
		int op2 = arr[j] + f(i, j-1, 1-par);
		return dp[i][j][par] = max(op1, op2);
	}
	else{
		int op1 = f(i+1, j, 1-par) - arr[i];
		int op2 = f(i, j-1, 1-par) - arr[j];
		return dp[i][j][par] = min(op1, op2);
	}

}

void solve()
{

	cin >> n;
	memset(dp, -1, sizeof(dp));

	rep(i, 1, n+1) cin >> arr[i];

	cout << f(1, n, 0) << endl;
		
}			 	

int32_t main(){
	fast();
    int t = 1;
    // cin>> t;
    while(t--){
    	solve();
    }
	starboy1299();
}


