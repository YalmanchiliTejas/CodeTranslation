#include <bits/stdc++.h>

using namespace std;

#define int long long

using ll = long long;
using pii =  pair<int, int>;

const int IINF =  0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
const ll MOD = 1e9+7;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)

#define rep(i,n) for_(i,0,n)
#define rrep(i,n) rfor_(i,0,n)

#define pb push_back
//#define eb emplace_back
#define mp make_pair
#define ft first
#define sd second

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define rev(a) reverse(all(a))

#define endl '\n'

const int limit = 100007;

char s[7];
int n;

signed main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin>>s;
	n = strlen(s);
	rep(i, n-1) {
		if(s[i]=='A' && s[i+1]=='C') {
			cout<<"Yes"<<endl;
			return 0;
		}
	}

	cout<<"No"<<endl;

	return 0;
}
