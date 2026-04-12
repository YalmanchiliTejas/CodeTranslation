#include <iostream>
#include <cstdio>
#include <queue>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;

int fact(int n){
    int kekka = 1;
    REP(i,n ){
        kekka *= (i + 1);
    }
    return kekka;
}

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    int a[28];
    int b[28];
    REP(i, M){
        cin >>a[i] >> b[i];
    }
    int route[5040][8];
    REP(i, fact(N - 1)){
        route[i][0] = 1;
        int katamari = i ;
        vector<int> katamarisuuji;
        REP(j, N-1){
            katamarisuuji.push_back(j + 2);
        }
        REP(j, N - 2){
            int sanshou =(katamari) / fact(N - j - 2);
           // printf("%d,%d\n",sanshou,katamari);
            route[i][j + 1] = katamarisuuji[sanshou];
            katamarisuuji.erase(katamarisuuji.begin() + sanshou);
            katamari -=sanshou* fact(N - j - 2);
           // printf("%d", route[i][j + 1]);
        }
        route[i][N - 1] = katamarisuuji[0];
       // printf("\n");
    }
    int houhou = 0;
    int mitigaaru = 0;
    REP(i, fact(N - 1)){
        REP(j, N - 1){
            mitigaaru = 0;
            REP(k, M){
              //  printf("%d,%d\n", route[i][j], route[i][j+1]);
                if((route[i][j] == a[k] && route[i][j + 1] == b[k]) || (route[i][j] == b[k] && route[i][j + 1] == a[k])){
                    mitigaaru = 1;
                   // printf("aru\n");
                    break;
                }
            }
            if(mitigaaru == 0) {break;}
        }
        if(mitigaaru == 1) houhou++;
    }
    cout << houhou << endl;
}
