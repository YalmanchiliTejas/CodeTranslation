#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define ull unsigned long long
#define ll long long
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}

#define max(a,b) (a>b?a:b)
ll N, K;
ll dp[100005];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> N >> K;
	if (K==0) {cout << N*N << endl; return 0;}
	dp[0] = 0;

	rep(n,1,N+1) {
		ll c = N/n;
		ll res = N-c*n;
		dp[n] = dp[n-1] + c*max(n-K, 0) + max(res-K+1,0); 
	}

	cout << dp[N] << endl;
}