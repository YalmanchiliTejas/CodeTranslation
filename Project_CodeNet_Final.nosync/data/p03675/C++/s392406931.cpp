/*input
4
1 2 3 4
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define fi first
#define se second
#define INF    1<<30
#define NEGINF -(1<<30)
#define LINF   1<<60
#define EPS 1e-10
#define PI 2 * acos(0)
#define NULO -1
#define endl '\n'

const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int cmp(double x, double y = 0, double tol = EPS){ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }


ll esq[212345], dir[212345];

int main(){
	ll n, a, d=0, e=0, md;
	
	scanf("%lld", &n);

	rep(i, 0, n){
		scanf("%lld", &a);
		if(i==0) md = a;
		else{
			if(n&1){
				//printf("impar\n");
				if(i&1){
					dir[d] = a;
					d++;
					//printf("i impar\n");
					
				}else{
					//printf("i par\n");
					esq[e] = a;
					e++;
				}

			}else{
				if(i&1){
					esq[e] = a;
					e++;
				}else{
					dir[d] = a;
					d++;
				}
			}
		}
	}

	per(i, 0, e){
		printf("%lld ", esq[i]);
	}
	printf("%lld", md);
	rep(i, 0, d){
		printf(" %lld", dir[i]);
	}
	puts("");



return 0;
}