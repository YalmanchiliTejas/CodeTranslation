#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

int n, m;
vector<VI> r;
int rec(int s, int z){
	if(z == (1<<n) -1){
		return 1;
	}
	int rt =0;
	for(auto x: r[s]){
		if(z>>x & 1) continue;
		z |= 1<<x;
		rt += rec(x, z);
		z &= ~(1<<x);
	}
	return rt;
}
int main(){
	//cin.tie(0); ios_base::sync_with_stdio(false);
	cin >>n >>m;
	r.resize(n);
	rep(i, m){
		int a,b;
		cin >>a >>b;
		r[a-1].push_back(b-1);
		r[b-1].push_back(a-1);
	}
	int z = 1;
	cout << rec(0, z) <<"\n";
	return 0;
}