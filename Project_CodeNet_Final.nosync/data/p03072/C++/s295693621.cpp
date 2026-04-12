#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define printjudge(cond) {if(cond) printf("Yes\n"); else printf("No\n");}
#define printans(ans) {printf("%d\n",(ans));}
#define intscan(x) {scanf("%d", &x);}
#define Ntimes(N) for(int i=0; i<N; i++)
#define min(x,y) (((x)<(y)) ? (x) : (y))
#define max(x,y) (((x)>(y)) ? (x) : (y))
typedef int* intarray;
typedef char* string;

int main(){
    int N, H, max = 0, ans = 0;
    intscan(N);
    Ntimes(N){
        intscan(H);
        if(H>=max) {ans++; max = H;}
    }
    printans(ans);
    return 0;
}