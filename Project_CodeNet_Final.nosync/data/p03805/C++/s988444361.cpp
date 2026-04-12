#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse
// struct Edge {
//   int to, id;
//   Edge(int a, int b): to(a), id(b) {}
// };

int a[10][10];


int main(){

	int n,m;cin>>n>>m;

	rep(i,m) {
		int c,d;cin>>c>>d;c--;d--;
		a[c][d]=a[d][c]=1;
	}

    int array[n-1];

    rep(i,n-1) array[i]=i+1;

	ll ans =0;

    do{
    	bool ok = true;
    	if (!a[0][array[0]]) ok = false;
    	rep(i,n-2) {
    		if (!a[array[i]][array[i+1]]) {
				ok = false;
				break;
    		}
    	}
    	if (ok) ans++;
    }while(next_permutation(array,array+n-1));

	cout<<ans<<endl;

    return 0;
}