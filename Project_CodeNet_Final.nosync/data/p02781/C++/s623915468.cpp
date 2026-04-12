#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    string s;
    cin>>s;
    long long int c;
    cin>>c;
    long long int digit_num = s.size();
    long long int zero_num = digit_num - c;
  if(zero_num < 0){
    cout << 0 << endl;
    return 0;
  }
    //cout << zero_num << endl;
    vector<vector<vector<long long int>>> dp(digit_num+1, vector<vector<long long int>>(2, vector<long long int>(120, 0)));
    long long int x0 = (long long int)(s[0] - '0');
    dp[0][0][0] = x0-1 ;
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    FOR(i,1,digit_num){
        long long int xi = (long long int)(s[i] - '0');
        //cout << xi << endl;
        if(xi==0){
            dp[i][0][0] += dp[i - 1][0][0] * 9 + dp[i - 1][0][0 + 1] * 0 + dp[i - 1][1][0] * (0) + dp[i - 1][1][0 + 1] * 0;

            REP(j,110){
                
                dp[i][0][j+1]+=dp[i - 1][0][j] * 1 + dp[i - 1][0][j + 1] * 9 + dp[i - 1][1][j] * (0) + dp[i - 1][1][j + 1] * 0;
         
                //dp[i][1][j]=dp[i - 1][0][j] * 9 + dp[i - 1][0][j + 1] * 0 + dp[i - 1][1][j] * (0) + dp[i - 1][1][j + 1] * 0;
                dp[i][1][j+1]+=dp[i - 1][0][j] * 0 + dp[i - 1][0][j + 1] * 0 + dp[i - 1][1][j] * (1) + dp[i - 1][1][j + 1] * 0;
            }
        }else{
            dp[i][0][0] += dp[i - 1][0][0] * 9 + dp[i - 1][0][0 + 1] * 0 + dp[i - 1][1][0] * (xi-1) + dp[i - 1][1][0 + 1] * 0;

            REP(j,110){
                
                dp[i][0][j+1]+=dp[i - 1][0][j] * 1 + dp[i - 1][0][j + 1] * 9 + dp[i - 1][1][j] * (1) + dp[i - 1][1][j + 1] * (xi-1);
                dp[i][1][j]+=dp[i - 1][0][j] * 0 + dp[i - 1][0][j + 1] * 0 + dp[i - 1][1][j] * (1) + dp[i - 1][1][j + 1] * 0;
                //dp[i][1][j+1]=dp[i - 1][0][j] * 0 + dp[i - 1][0][j + 1] * 0 + dp[i - 1][1][j] * (0) + dp[i - 1][1][j + 1] * 0;
            }
            
        }

      /*  cout << i << endl;
        FOR(j,i,i+5){
            cout<<"j="<<j<<" " << dp[i][0][j] << " " << dp[i][1][j] << endl;
        }
        cout << endl;*/
    }
    cout << dp[digit_num - 1][1][zero_num]+ dp[digit_num - 1][0][zero_num] << endl;
    return 0;
}
