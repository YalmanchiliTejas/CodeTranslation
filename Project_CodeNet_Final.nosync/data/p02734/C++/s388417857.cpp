#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define LL long long

LL F[3005],C[3005];
int n,s;
int A[3005];
int mo = 998244353;

int main(){
	
	scanf("%d%d",&n,&s);
	for ( int i = 1; i <= n; i++ ) scanf("%d",&A[i]);
	
	LL ans = 0;
	for ( int i = 1; i <= n; i++ ){
		
		for ( int j = s- A[i]; j >= 0; j-- ){
			F[j+A[i]] += F[j];
			F[j+A[i]] %= mo;
		}
		
		F[A[i]] += i;
		F[A[i]] %= mo;
		
		LL lo = F[s];
		ans = ( ans + lo) % mo;
//		cout << C[s] << " " << F[s] << " " << ans << " " << diff << endl;
	}
	printf("%lld\n",ans);
	return 0;
}
