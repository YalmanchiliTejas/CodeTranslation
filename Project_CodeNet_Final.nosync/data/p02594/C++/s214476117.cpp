/*input
25
*/

// Nihesh Anderson - knandy

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
ll MOD=1000000007;

#define endl '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
ll INF = 2000000000000000001;
long double EPS = 1e-9;
ll power(ll a, ll n, ll md){if(n==0){return 1;}else{int res=power(a,n/2,md);res=(res*res)%md;if(n%2!=0){res=(res*a)%md;}return res;}}
random_device rndm;
mt19937 grndm(rndm());
void mix(int* a, int* b){shuffle(a,b,grndm);}

int main(){
	fast_cin();
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
	int x; cin >> x;
	if(x >= 30) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}


















