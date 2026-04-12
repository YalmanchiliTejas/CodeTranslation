#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define mod 998244353
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;
typedef pair<llint, llint> P;

int n;
string s;
int p[1<<18];
int dp[1<<19];
vector<int> vec;

void calc(int n, vector<int> &vec)
{
	if(n == 0){
		dp[1] = vec.front();
		return;
	}
	
	int N = 1<<n;
	vector<int> tmp(N/2);
	for(int i = 0; i < N; i+=2){
		int d = abs(vec[i] - vec[i+1]);
		if(s[d] == '0') tmp[i/2] = min(vec[i], vec[i+1]);
		else tmp[i/2] = max(vec[i], vec[i+1]);
	}
	calc(n-1, tmp);
	for(int i = 0; i < N/2; i++){
		int b = N/2+i;
		dp[(b<<1)+0] = dp[b];
	}
	
	for(int i = 1; i+1 < N; i+=2){
		int d = abs(vec[i] - vec[i+1]);
		if(s[d] == '0') tmp[i/2] = min(vec[i], vec[i+1]);
		else tmp[i/2] = max(vec[i], vec[i+1]);
	}
	int d = abs(vec.back() - vec.front());
	if(s[d] == '0') tmp.back() = min(vec.back(), vec.front());
	else tmp.back() = max(vec.back(), vec.front());
	
	calc(n-1, tmp);
	for(int i = 0; i < N/2; i++){
		int b = N/2+i;
		dp[(b<<1)+1] = dp[b];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	s = "#" + s;
	
	llint N = 1<<n;
	for(int i = 0; i < N; i++) cin >> p[i];
	for(int i = 0; i < N; i++) vec.push_back(p[i]);
	
	calc(n, vec);
	
	for(int i = 0; i < N; i++){
		int b = N + i;
		cout << dp[b] << "\n";
	}
	flush(cout);
	
	return 0;
}
