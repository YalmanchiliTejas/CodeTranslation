#include <iostream>

#define REP(i, a, b) for ( int i = (a); i < (b); i++ )
#define REVREP(i, a, b) for ( int i = (a); i >= (b); i--)
#define DEBUG_INT(var) printf("the value of "#var" is %d\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) REP(i, begin, end) PRINT_ARRAY(name, i)

using namespace std;

typedef long long ll;

ll ans = 100000000000;
ll A, B, C, X, Y;

int main(void) {
    scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &X, &Y);

    for (int i = 0; i <= max(X,Y)*2; i +=2 ) {
    	ll sum = i * C;
    	sum += max(0LL, (X - (i/2))) * A;
    	sum += max(0LL, (Y - (i/2))) * B;
    	ans = min(ans, sum);
    }
    
    printf("%lld\n", ans);

	return 0;
}
