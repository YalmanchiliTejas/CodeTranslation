#include <cstdio>
#include <cstring>
using namespace std;

#define A 0
#define B 1

typedef long long ll;

const int MAXN = 1e5+5;
int N, color[MAXN];
char s[MAXN];
int main () {
    bool good = false;
    scanf("%d%s", &N, s);
    for (int i=0; i<N; i++) color[i] = -1;
    for (int i=0; i<2 && !good; i++) {
        for (int j=0; j<2 && !good; j++) {
            color[B] = j;color[A] = i;
            int k = B;
            while (k < N) {
                // si a los lados son iguales
                if ((color[k] == 1 && s[k] == 'x') || 
                        (color[k] == 0 && s[k] == 'o')) {
                    if (k == N-1 && color[k-1] == color[A]) {
                        if ((color[A] == 0 && s[A] == 'o') 
                                || (color[A] == 1 && s[A] == 'x')) {
                            if (good = (color[k] == color[B])) break;
                        }
                        else if ((color[A] == 0 && s[A] == 'x') 
                                || (color[A] == 1 && s[A] == 'o')) {
                            if (good = (color[k] != color[B])) break;
                        }
                    }
                    color[(k+1)%N] = color[k-1];
                }
                // si a los lados son diferentes
                else if  ((color[k] == 0 && s[k] == 'x') || 
                        (color[k] == 1 && s[k] == 'o')){
                    if (k == N-1 && color[k-1] != color[A] ) {
                        if ((color[A] == 0 && s[A] == 'o') 
                                || (color[A] == 1 && s[A] == 'x')) {
                            if (good = (color[k] == color[B])) break;
                        }
                        else if ((color[A] == 0 && s[A] == 'x') 
                                || (color[A] == 1 && s[A] == 'o')) {
                            if (good = (color[k] != color[B])) break;
                        }
                    }
                    color[(k+1)%N] = !color[k-1];
                }

                k++;
            }
        }
    }

    if (!good) {
        printf("-1\n");
    } else {
        for (int i=0; i<N; i++) {
            if (color[i] == 0) printf("S");
            else printf("W");
        }
        printf("\n");
    }
}
