#include <iostream>
#include <cstdio>

#define REP(i, a, b) for ( int i = (a); i < (b); i++ )
#define REVREP(i, a, b) for ( int i = (a); i >= (b); i--)
#define DEBUG_INT(var) printf("the value of "#var" is %d\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) REP(i, begin, end) PRINT_ARRAY(name, i)

using namespace std;

typedef long long ll;

int H, W;
int w[105], h[105];
char a[105][105];

int main(void) {
    scanf("%d %d", &H, &W);


    REP(i, 0, H) {
    	scanf("%s", &a[i]);
    }
    
    REP(i, 0, H) {
      REP(j, 0, W) {
        if (a[i][j] == '#') {
          h[i] = 1;
          w[j] = 1;
        }
      
      }
    
    }

    

    REP(i, 0, H) {
    	if (!h[i]) continue;
    	REP(j, 0, W) {
    	  if (!w[j]) continue;
    		printf("%c", a[i][j]);
    	}
    	printf("\n");
    }

	return 0;
}
