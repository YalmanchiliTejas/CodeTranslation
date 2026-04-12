#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[24]="FESTIVAL";
LL up[8],d[8];
void get(int id,LL v){
    if(!id){
        while(d[id]<v){
            printf("F");
            d[id]++;
        }
        return;
    }
    while(d[id]<v){
        if(d[id-1]<d[id]&&d[id-1]<up[id-1]){
            get(id-1,d[id]);
        }
        printf("%c",s[id]);
        d[id]+=d[id-1];
    }
}
int main(){
    up[0]=256;
    d[0]=1;
    REPP(i,1,8)up[i]=up[i-1]*256,d[i]=1;
    LL K;
    cin>>K;
    REP(i,7)printf("%c",s[i]);
    while(K){
        int me=K&255;
        REP(i,me)printf("L");
        K-=me;
        K/=256;
        if(K){
            get(6,d[6]*256);
        }
    }
    puts("");
    return 0;
}
