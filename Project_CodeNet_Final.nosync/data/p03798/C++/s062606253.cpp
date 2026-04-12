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
	VI sd(n);
	rep(i, n) sd[i] = s[i]=='o'? 0: 1;
	rep(i, 4){
		VI ck(n+1, -1);
		bool ok=true;
		ck[0] = i&1; ck[1] = (i>>1) &1;
		rep2(i, 1, n){
			if(ck[i] == sd[i] ) ck[i+1]=ck[i-1];
			else ck[i+1] = ck[i-1] ^ 1;
		}
		if(ck[0] != ck[n]) ok=false;
		if(ck[0]==sd[0] && ck[1] != ck[n-1]) ok=false;
		if(ck[0]!=sd[0] && ck[1] == ck[n-1]) ok=false;
		if(ok){
			rep(i, n) cout <<(ck[i]==0? 'S':'W');
			cout <<"\n";
			return 0;
		}
	}
	puts("-1");
	return 0;
}
