/*input
6
4 2 9 7 1 5
*/
 
// author - Madhav Thakker
 
#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace std;
 
#define ll long long
#define ld long double
#define int ll
#define endl '\n'

typedef pair<int, int> pii; 
typedef pair<ld, ld> pdd;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FileIn(file) freopen(file, "r", stdin)
#define FileOut(file) freopen(file, "w", stdout)
#define all(c) c.begin(), c.end() 
#define tr(container, it )\
for(__typeof__(container.begin()) it = container.begin(); it != container.end(); it++) 
#define present(container, element) (container.find(element) != container.end())  //map, set
#define cpresent(container, element) (find(aint(container),element) != container.end()) //vector
#define what_is(x) cout << #x << " is " << x << endl; 
#define all(c) c.begin(), c.end() 
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
const int MOD = 1e9+7;
 
 
int fast_pow(int a, int b){
	int res = a, ret = 1;
	while(b>0){
		if(b%2)
			ret = (ret*res)%MOD;
		res = (res*res)%MOD;b/=2;
	}
	return ret;
}
 
// --
// -- 
// -- 
// std::cout << std::fixed;
// std::cout << std::setprecision(26) << f << '\n';
// str = to_string(n)
// stoi , stoll, stol
// sort(arr, arr+n, greater<int>());
// fill(prefix.begin(), prefix.end(), 0);
// 
// 
 
 
 
////
const int maxN = 3e3+7;
int arr[maxN];
int dp[maxN][maxN][2];  // 0 - max X - Y

////

int n;
int getans(int l, int r, int turn){
	if(l == r){
		return arr[l];
	}
	if(l > r or r < 0){
		return 1e10;
	}
	if(dp[l][r][turn]!=-1){
		return dp[l][r][turn];
	}
	if(turn==1){
		dp[l][r][1] =  max(arr[l] - getans(l+1, r, turn*1), arr[r] - getans(l, r-1, turn*1));
	}
	else if(turn == -1){
		dp[l][r][0] =  max(arr[l] - getans(l + 1, r, turn*1), arr[r] - getans(l, r-1, turn*1));
	}
	return dp[l][r][turn];
}

signed main(){
 
	fastio;
	time_t time_t1, time_t2;
	time_t1 = clock();
 
	////////////////////////////////

	int t = 1;
	// cin >> t ;

	while(t--){
		memset(dp, -1, sizeof dp);
		cin >> n;
		for (int i = 0; i < n; ++i){
			cin >> arr[i];
		}
		int ans = getans(0, n-1, 1);
		cout << ans << endl;
	}
 	
	///////////////////////////////
	// 
 
	time_t2 = clock();
	// cerr << "time taken :" << time_t2 - time_t1 << endl;
 
	return 0;
}
