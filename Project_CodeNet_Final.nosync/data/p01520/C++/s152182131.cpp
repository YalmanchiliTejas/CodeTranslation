#include <cstdio>

int main(){
    int N, T, E;
    scanf("%d %d %d", &N, &T, &E);

    for(int i=1;i<=N;i++){
        int x;
        scanf("%d", &x);

        int t;
        for(t=0;t<T-E;t+=x);
        if(t <= T+E){printf("%d\n", i); return 0;}
    }
    puts("-1");
}