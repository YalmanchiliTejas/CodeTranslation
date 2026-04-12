//At Coder -> Sum of Digits
//statement : Find number of integers between 1 and K such that sum of digits is multiple of D
//constraints : 1 <= K <= 1e10000   and     1 <= D <= 100
#include<bits/stdc++.h>
using namespace std;
const int MAXD = 102, MOD=1e9+7;
int d, dp_anterior[MAXD][2], dp_atual[MAXD][2];
// 0 => not smaller already
// 1 => smaller already
string k;
int main(){
    cin>>k>>d;
    //BASE CASE
    dp_anterior[0][0] = 1;

    for(int cur_digit=0; cur_digit<(int)k.size(); cur_digit++){
        for(int soma=0; soma<d; soma++){
            for(int candidate=0; candidate<=k[cur_digit]-'0'; candidate++){//for those NOT smaller already
                if(candidate < k[cur_digit]-'0'){//about to become smaller already
                    dp_atual[(soma+candidate)%d][1] = (dp_atual[(soma+candidate)%d][1] + dp_anterior[soma][0])%MOD;
                }else{//remains NOT smaller already
                    dp_atual[(soma+candidate)%d][0] = (dp_atual[(soma+candidate)%d][0] + dp_anterior[soma][0])%MOD;
                }
            }
            for(int candidate=0; candidate<=9; candidate++){//for those smaller already
                    dp_atual[(soma+candidate)%d][1] = (dp_atual[(soma+candidate)%d][1] + dp_anterior[soma][1])%MOD;
            }
        }
        for(int i=0; i<MAXD; i++){
            for(int j=0; j<2; j++){
                dp_anterior[i][j] = dp_atual[i][j];
                dp_atual[i][j] = 0;
            }
        }
    }
    cout << (dp_anterior[0][0]+dp_anterior[0][1] + MOD - 1)%MOD << endl;//excluir 0 da resposta
}