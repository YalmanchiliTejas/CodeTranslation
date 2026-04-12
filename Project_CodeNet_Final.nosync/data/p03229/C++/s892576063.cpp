#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,a,b) for(int i = (a); i >= (b); i--)
#define mst(a,b) memset(a,b,sizeof(a));
#define clr(a) mst(a,0);
#define pb  push_back
#define mp  make_pair
#define first fi
#define second se
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
ll _gcd(ll a,ll b){return b?_gcd(b,a%b):a;}
const double PI = acos(-1);
//head
const int maxn = 1e5 + 11;
int a[maxn];
int main(int argc, char const *argv[]){

	int n; cin >> n;
	rep(i,1,n) cin >> a[i];
	sort(a+1,a+1+n);
	// 1 2 3 6 8
	int l = 1,r = n;
	ll sum = 0;
	while(r-l+1 > 3){
		sum += 2ll*(a[r]-a[l]);
		r--;l++;

	}
	if(r-l+1 == 3){
		sum += max(2ll*a[r]-1ll*a[r-1]-1LL*a[l],1ll*a[r]+1ll*a[r-1]-2ll*a[l]);
	}else if(r-l+1 == 2){
		sum += (ll)(a[r] - a[l]);
	}
	cout << sum << endl;



	return 0;
}










