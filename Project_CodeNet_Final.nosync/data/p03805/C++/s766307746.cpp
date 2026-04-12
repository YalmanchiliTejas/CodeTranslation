#include <stdio.h>
#include <stdlib.h>

int ans = 0;

int isCompSeq(int N, int* seq) {
    for(int i=0;i<N;i++) {
        if(seq[i] == 0) {
            return 0;
        }
    }

    return 1;
}

void copySeq(int N, int* seq, int* ne) {
    for(int i=0;i<N;i++) {
        ne[i] = seq[i];
    }
}

void printSeq(int N,int* seq) {
    for(int i=0;i<N;i++) {
        printf("%d,", seq[i]);
    }

    printf("\n");
}

void judge(int N, int* edge, int s, int* seq) {
//  printSeq(N, seq);

    if(isCompSeq(N, seq)) {
        ans++;
        return;
    }

    int* ne;
    for(int i=0;i<N;i++) {
        if(edge[i*N + s] && seq[i] == 0) {
            ne = (int*)malloc(sizeof(int)*N);
            copySeq(N, seq, ne);
            ne[i] = 1;
            judge(N, edge,i,ne);
            free(ne);
        }
    }
}


int main() {

    int N,M;

    scanf("%d %d", &N, &M);

    int edge[N*N];

    for(int i=0;i<N;i++) {
        for(int t=0;t<N;t++) {
            edge[i*N+t] = 0;
        }
    }

    int a,b;
    for(int i=0;i<M;i++) {
        scanf("%d %d", &a, &b);
        edge[(b-1)*N+(a-1)] = 1;
        edge[(a-1)*N+(b-1)] = 1;
    }

    int* seq;
    for(int i=0;i<N;i++) {
        if(edge[i*N + 0]) {
            seq = (int*)malloc(sizeof(int)*N);
            for(int t=0;t<N;t++) {
                seq[t] = 0;
            }
            seq[0] = 1;
            seq[i] = 1;
            judge(N, edge, i, seq);
            free(seq);
        }
    }

    printf("%d\n", ans);

    return 0;
}
