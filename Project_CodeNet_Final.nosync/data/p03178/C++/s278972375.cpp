#include <iostream>
#include <vector>
using namespace std;
const long long int MOD = 1000000007; 


int main() {
    string s;
    int d, lim;
    cin >> s;
    cin >> d;

    int length = s.size()+1;
    long long int dp[10010][2][110];

    for(int i=0;i<length;i++) {

        for(int j=0;j<2;j++) {

            for(int k=0;k<d;k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    
    for(int i=0;i<length;i++) {

        for(int smaller=0;smaller<2;smaller++) {

            if(smaller==1) {
                lim = 9;
            } else {
                lim = s[i]-'0';
            }

            for(int j=0;j<d;j++) {
                
                for(int k=0;k<lim+1;k++) {
					
                    dp[i+1][smaller || k < lim][(j+k)%d] += dp[i][smaller][j];
                    dp[i+1][smaller || k < lim][(j+k)%d] %= MOD;
                  
                }
            }
        }
    }

    cout << (dp[s.size()][1][0] + dp[s.size()][0][0] - 1 + MOD) % MOD  << endl;
}