#include <iostream>

#define REP(i, a, b) for ( int i = (a); i < (b); i++ )
#define REVREP(i, a, b) for ( int i = (a); i > (b); i--)

using namespace std;

int N;
int H[105];

int main(void) {
    scanf("%d", &N);
    REP(i, 0, N) scanf("%d", &H[i]);

    int max = H[0];
    int ans = 0;
    REP(i, 0, N) {
    	if ( H[i] >= max ) {
    		ans++;
    		max = H[i];
    	}
    }
    
    printf("%d\n", ans);

	return 0;
}
