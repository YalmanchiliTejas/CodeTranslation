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
template <class T, class T2> void amin(T& a,T2 b){ if(a > b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >>n >>s;
	VI sd(2*n);
	rep(i, 2*n) sd[i] = s[i%n]=='o'? 0: 1;
	rep(i, 4){
		VI ck(2*n+2, -1);
		ck[0] = i&1; ck[1] = (i>>1) &1;
		rep2(i, 1, 2*n){
			if(ck[i] == sd[i] ) ck[i+1]=ck[i-1];
			else ck[i+1] = ck[i-1] ^ 1;
		}

		bool ok=true;
		rep(i, n) if(ck[i] != ck[i+n]) ok=false;
		//for(auto x :ck) cerr<<x<<" "; dbg("::", ok);
		if(ok){
			rep(i, n) cout <<(ck[i]==0? 'S':'W');
			cout <<"\n";
			return 0;
		}
	}
	puts("-1");
	return 0;
}
