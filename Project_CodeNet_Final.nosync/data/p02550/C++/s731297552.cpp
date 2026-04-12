
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<lli> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ii> vii;

#define deb(x) cout << #x": " << (x) << endl;


// ---- コーディングはここから！ ('-')7
const lli MOD = 998244353;
void solve(){
	lli a,b,c; cin>>a>>b>>c;
	lli u = b%c;
	if(a<c){
		lli sum = 0;
		fore(i,0,a){
			sum+=b;
			b=(b*b)%c;
		}
		cout<<sum<<ENDL;
		return;
	}

		map<int,int>mark;
		vl sum(1,0);
		lli z,last;
		for(int i = 1; ;i++){
			if(mark.count(b)){
				z =i-mark[b];
				last = mark[b]-1;
				break;
			}
			mark[b]=i;
			sum.pb(sum.back()+b);
			b=(b*b)%c;
		}
		lli res = 0;
		lli aux = sum.back()-sum[last];
		lli h = (a - last)/z;
		res+= h*aux + sum[last+((a - last)%z)];
		cout<<res<<ENDL;

}
int main(){_
	//int t; cin>>t; while(t--)
	solve();
}
