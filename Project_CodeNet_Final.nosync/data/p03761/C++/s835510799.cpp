#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll,ll> pii;
const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2>
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }



int main(){
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	vector<string> s(n);
	rep(i, n) cin >>s[i];
	
	VI ssk(26, 99999);
	rep(i, n){
		VI w(26);
		rep(j, sz(s[i])) w[s[i][j]-'a']++;
		rep(j, 26) ssk[j] = min(ssk[j], w[j]);
	}
	rep(i, 26) cout << string(ssk[i], 'a'+i);
	cout <<"\n";
	return 0;
}