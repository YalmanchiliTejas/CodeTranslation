#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int n;cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(ALL(a));
	ll ans = abs(a[0] - a[n - 1]);
	int l = 0;
	int r = n - 1;
	for(int i = 0; i < n - 2; i++) {
		if (i % 2 == 0){
			l++;
			ans += abs(a[l] - a[r]);
		}
		else{
			r--;
			ans += abs(a[l - 1] - a[r]);
		}
	}
	l = 0;r = n - 1;
	ll tmp = abs(a[0] - a[n - 1]);
	for(int i = 0; i < n - 2; i++) {
		if (i % 2 == 0){
			r--;
			tmp += abs(a[l] - a[r]);
		}
		else{
			l++;
			tmp += abs(a[l] - a[r + 1]);
		}
	}
	cout << max(tmp,ans) << endl;
	
	return 0;
}