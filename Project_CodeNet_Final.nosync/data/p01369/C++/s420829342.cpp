#include <stdio.h>
#include <string.h>
#include <set>
#define in(x) insert(x)
using namespace std;
set<char>RB;int main() {
    char T[999];RB.in('y'),RB.in('u'),RB.in('i'),RB.in('o'),RB.in('p'),RB.in('h'),RB.in('j'),RB.in('k'),RB.in('l'),RB.in('n'),RB.in('m');int i,j,k;while (1) {
        scanf("%s",&T);if (T[0]=='#') break;i=strlen(T)-1,j=0;k=RB.find(T[i])!=RB.end();
		while (i--) if (k!=(RB.find(T[i])!=RB.end())) j++,k=1-k;printf("%d\n",j);
    }
    return 0;
}