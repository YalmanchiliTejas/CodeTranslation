#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct team_t{
    int point;
    int rank;
};

int main(){
    team_t teams[101];
    int flg[31];
    memset( flg, 0, sizeof(flg) );
    while(1){
        int n, p;
        scanf("%d,%d", &n, &p);
        if( !n && !p )  break;
        teams[n].point = p;
        flg[p]++;
    }
    int r = 1;
    for( int i=30; i>=0; i-- ){
        if( flg[i] ){
            for( int j=0; j<=100; j++ ){
                if( teams[j].point == i ){
                    teams[j].rank = r;
                }
            }
            r++;
        }
    }
    int k;
    while( scanf("%d", &k) == 1 ){
        printf("%d\n", teams[k].rank);
    }
    return 0;
}