#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll

typedef pair<int,int> pi;
typedef vector<int> vi;
 
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

template<typename T> void max_self(T &a, T b) { a = max(a,b); return;}
template<typename T> void min_self(T &a, T b) { a = min(a,b); return;}
 
const int nax = 2e6 + 5;
const int mod = 1e9 + 7;

int modExpo(int a,int b,int c){
	if(b == 0) return 1;
	int answer = 1;
	while(b){
		if(b & 1) answer = ((answer % c) * (a % c)) % c;
		a = ((a % c) * (a % c)) % c;
		b /= 2; 
	}
	
	return answer;
}

int d;
int dp[10005][125][2];
string s;

int f(int index,int sum,int flag){
	int n = (int)s.size();
	if(index == n){
		if(sum == 0) return 1;
		return 0;
	}
	
	assert(index >= 0 && index <= 10000);
	assert(sum >= 0 && sum <= 100);
	assert(flag >= 0 && flag <= 1);
	
	if(dp[index][sum][flag] != -1) return dp[index][sum][flag];
	
	int limit = 9;
	if(flag) limit = s[index] - '0';
	
	int ans = 0;
	for(int i = 0; i <= limit; ++i){
		int newflag = flag;
		if(flag && i == limit) newflag = 1;
		else newflag = 0;
		ans = ((ans % mod) + f(index + 1,(sum + i) % d,newflag) % mod) % mod; 
	}
	
	dp[index][sum][flag] = ans;  
	return ans;
}

signed main(){
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--){
		cin >> s;
		cin >> d;
		
		memset(dp,-1,sizeof(dp));
		
		int res = f(0,0,1) - 1;
		if(res == -1) res += mod;
		cout << res;
	}
	
	return 0;
}
