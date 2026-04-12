#include <bits/stdc++.h>
using namespace std;

int dp_first[10010][110];
int dp[110];

int main(){
    string s;
    cin >> s;
    int D; cin >> D;
    int N = s.size();
    const int MOD = pow(10,9)+7;
    dp_first[0][0]=1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<D; j++){
            for(int k=0; k<=9; k++){
                dp_first[i][(j+k)%D] +=dp_first[i-1][j];
                dp_first[i][(j+k)%D] %=MOD;
            }
        }
    }

    int rui=0;
    for(int i=0; i<N; i++){
        int k=s.at(i)-'0';
        for(int j=0; j<k; j++){
            for(int l=0; l<D; l++){
                dp[(l+j+rui)%D] += dp_first[N-i-1][l];
                dp[(l+j+rui)%D] %= MOD;
            }
        }
        rui +=k;
    }
    if(rui%D==0) dp[0]++;
    dp[0] = (dp[0]+MOD-1)%MOD; //0を除く
/*    int num=0;
    for(int i=0; i<N; i++){
        num = num*10+ s.at(i)-'0';
        num %= D;
    }
    if(num==0) dp[0]++;
*/    cout << dp[0] << endl;
}