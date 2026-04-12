#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;  
#define rep(i,n) for(int i=0; i<int(n); ++i)
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef long long ll;
typedef pair<int,int> PII;

void solve(){
	int n,m,k;
	int x,y,z;
	deque<int> q;
	cin >> n;
	rep(i,n){
		cin >> x;
		if(i&1) q.push_front(x); else q.push_back(x);
	}
	if (n&1) reverse(q.begin(), q.end());
	rep(i,n){
		cout << q[i];
		if(i<n-1) cout << ' '; else cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	// #ifdef LOCAL
	// 	freopen("a.in", "r", stdin);
	// #endif
	solve();
	return 0;
}