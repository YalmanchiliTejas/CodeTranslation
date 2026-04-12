#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; ll k;
	cin >>n >>k;
	
	
	vector<VL> z = {{1, 0}};
	rep(i, 50){
		z.push_back({z.back()[0]*2+1, z.back()[1]*2+2});
	}

	auto f=[&](auto f, int rn, ll rx)-> ll{
		if(rn ==0) return rx<=0? 0LL: 1LL;
		else if( rx<=1 + z[rn-1][0] + z[rn-1][1]) return f(f, rn-1, rx-1);
		else return z[rn-1][0] + 1LL + f(f, rn-1, rx-2-z[rn-1][0] - z[rn-1][1]);
	};
	
	cout << f(f, n, k) <<"\n";;
	return 0;
}
