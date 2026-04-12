#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi as(n);
	trav(x, as) cin >> x;
	deque<int> bs;
	rep(i,0,n){
		if(i%2 == 0) bs.push_back(as[i]);
		else bs.push_front(as[i]);
	}
	if(n % 2 == 1) reverse(all(bs));
	trav(x, bs) cout << x << ' ';
	cout << endl;
}