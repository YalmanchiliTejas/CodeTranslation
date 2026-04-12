#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cassert>
#include<deque>
using namespace std;

#define sz(x) (int)(x.size())
#define fr(i,a,b) for(int i=a;i<b;++i)
#define fdr(i,a,b) for(int i=b-1;i>=a;--i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
//////////////////////



void solve(){
	deque<int> q;
	int n;
	cin >> n;
	bool b = true;
	fr(i, 0, n){
		int v;
		cin >> v;
		if(b) q.pb(v);
		else q.push_front(v);
		b ^= 1;
	}
	if(!b) reverse(q.begin(), q.end());
	fr(i, 0, sz(q)) cout << q[i] << " ";
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();

	return 0;
}