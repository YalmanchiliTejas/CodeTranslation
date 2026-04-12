
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
template <class T> void amax(T& a,T b){if(a < b) a = b;}


ll fnc1(string sn, int q){
	//string sn = to_string(n);
	int cn=sz(sn); 
	ll ans =0;
	vector<VL> p(4, VL(2));
	p[0][0]=1;
	rep(i, cn){
		vector<VL> np(4, VL(2));
		rep(j, q)  rep(d, 10) {
			//int nk = k |(j>>d &1);
			int nj = j;
			if(d>0) nj = j+1;
			if(d < sn[i] -'0') np[nj][1] += p[j][0];
			else if(d== sn[i] -'0') np[nj][0] += p[j][0];
			np[nj][1] += p[j][1];
		}
		swap(p, np);
		ans += p[q][0] + p[q][1];
	}
	return ans;
}

int main(){
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int k;
	string sn;
	cin >>sn >>k;
	cout << fnc1(sn, k) <<"\n";;
	return 0;
}
