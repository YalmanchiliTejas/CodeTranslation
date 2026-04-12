#include <bits/stdc++.h>


#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}




int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	vector<VI> r(n);
	rep(i, m){
		int a, b; cin >>a >>b;
		r[a-1].push_back(b-1);
		r[b-1].push_back(a-1);
	}
	
	auto rec=[&](auto rec, int c, int zm)->ll{
		zm |= 1<<c;
		if(zm == (1<<n) -1) return 1;
		ll rt = 0;
		for(auto v: r[c]){
			if(zm >>v &1) continue;
			rt += rec(rec, v, zm);
		}
		return rt;
	};
	
	cout << rec(rec, 0, 0) <<"\n";
	return 0;
}
