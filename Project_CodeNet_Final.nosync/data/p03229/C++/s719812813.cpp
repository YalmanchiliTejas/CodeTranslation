#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	sort(a.rbegin(), a.rend());
	ll tans = 0;
	if(n%2){
		rep(ri,2){
			ll ans = 0;
			for(int  i = 0; i <= n/2-2;i++){
				ans += 2 * a[i];
			}
			ans += a[n/2-1];
			ans += a[n/2];
			for(int i = n/2+1; i < n; i++){
				ans -= 2 * a[i];
			}
			reverse(a.begin(), a.end());
			chmax(tans, ans*(ll)pow(-1,ri));
		}
	}else{
		rep(ri, 2){
			ll ans = 0;
			for(int i = 0; i <= n/2-2; i++){
				ans += 2 * a[i];
			}
			ans += a[n/2-1];
			ans -= a[n/2];
			for(int i = n/2+1; i < n; i++){
				ans -= 2 * a[i];
			}
			reverse(a.begin(), a.end());
			chmax(tans, ans * (ll)pow(-1, ri));
		}
		
	}
	cout << tans << endl;
}