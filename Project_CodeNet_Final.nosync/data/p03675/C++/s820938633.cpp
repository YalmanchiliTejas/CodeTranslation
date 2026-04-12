#include <bits/stdc++.h>


using namespace std ;
const int maxn = 2*100000+10 ;

typedef long long ll ;

ll d[maxn] ;
int n ;

int main(void){
	scanf("%d",&n) ;
	for(int i=1; i<=n; i++) scanf("%lld",&d[i]) ;
	if(n%2==0) {
		for(int i=n; i>=2; i-=2) printf("%lld ",d[i]) ;
		for(int i=1; i<n; i+=2) printf("%lld ",d[i]) ;
		printf("\n") ;
	} else {
		for(int i=n; i>=1; i-=2) printf("%lld ",d[i]) ;
		for(int i=2; i<=n; i+=2) printf("%lld ",d[i]) ;
		printf("\n") ;
	}

	return 0 ;
}

