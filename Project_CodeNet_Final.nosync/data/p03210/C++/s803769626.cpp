#include <iostream>

#define REP(i, a, b) for ( int i = (a); i < (b); i++ )
#define REVREP(i, a, b) for ( int i = (a); i >= (b); i--)
#define DEBUG_INT(var) printf("the value of "#var" is %d\n", var)
#define PRINT_ARRAY(name, i) printf("the value of "#name"[%d] is %d\n", (i), name[(i)])
#define DEBUG_ARRAY(name, begin, end) REP(i, begin, end) PRINT_ARRAY(name, i)

using namespace std;

int main(void) {
	int X;
    scanf("%d", &X);

    if (X == 7 || X == 5 || X == 3) puts("YES");
    else puts("NO"); 

	return 0;
}
