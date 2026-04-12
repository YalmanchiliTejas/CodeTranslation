#include <stdio.h>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
    int n;
    char s[100001];
    int animals[100001];
    
    scanf("%d %s", &n, s);
    for (int initial = 0; initial <= 3; initial++){
        animals[0] = initial & 1; // sheep:0, wolf:1
        animals[1] = initial >> 1;
        for (int i=2; i<n; i++){
            animals[i] = animals[i-2] ^ (s[i-1]=='x');
            if (animals[i-1] == 1){
                animals[i] = 1-animals[i];
            }
        }
        if (animals[n-2] ^ animals[n-1] ^ (s[n-1]=='x') == animals[0] &&
            animals[n-1] ^ animals[0] ^ (s[0] == 'x') == animals[1]){
//        if (1){
            for (int i=0; i<n; i++){
                putchar("SW"[animals[i]]);
            }
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}