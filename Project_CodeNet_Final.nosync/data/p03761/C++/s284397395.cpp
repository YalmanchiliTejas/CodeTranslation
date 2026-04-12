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
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n ;
	vector<VI> sk(n, VI(26));
	rep(i, n){
		string s;
		cin >>s;
		for(auto x: s) sk[i][x-'a']++;
	}
	
	rep(i, 26){
		int cnt = 9999;
		rep(j, n){
			cnt = min(cnt, sk[j][i]);
		}
		if(cnt > 0) cout << string(cnt, char(i+'a'));
	}
	cout <<"\n";
	return 0;
}
