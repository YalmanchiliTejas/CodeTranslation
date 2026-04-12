#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <type_traits>

using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;


const long long int mod = 1000000007;
const long long int INF = 1e18;

long long int N,M,K,A[200200],B[200200];string S;
//見ている番号
long long int dp[300][5][3]={};
pll BA[200020];

int main()
{
    cout << fixed << setprecision(18);
    cin>>S>>K;
    for(long long int i = 1; i <S[0]-'0' ; i++){
        dp[0][1][0]+=1;
    }
    dp[0][1][1]+=1;
    for(long long int i = 1; i < S.size(); i++){
        //次の桁から自由
        for(long long int j = 1; j < S[i]-'0'; j++){
            for(long long int k = 1; k <= 3; k++){
                dp[i][k+1][0]+=dp[i-1][k][1];
            }
        }
        //次の桁も不自由(0)
        if(S[i]=='0'){
            for(long long int k = 1; k <= 3; k++){
                dp[i][k][1]+=dp[i-1][k][1];
            }
        }else{
            for(long long int k = 1; k <= 3; k++){
                dp[i][k][0]+=dp[i-1][k][1];
            }
            //次の桁も不自由(!0)
            for(long long int k = 1; k <= 3; k++){
                dp[i][k+1][1]+=dp[i-1][k][1];
            }
        }
        //1~9
        for(long long int j = 1; j < 10; j++){
            for(long long int k = 1; k <= 3; k++){
                dp[i][k+1][0]+=dp[i-1][k][0];
            }
        }
        //0
        for(long long int k = 1; k <= 3; k++){
            dp[i][k][0]+=dp[i-1][k][0];
        }

        for(long long int j = 1; j < 10; j++){
            dp[i][1][0]+=1;
        }
        
    }
    
    cout<<dp[S.size()-1][K][0]+dp[S.size()-1][K][1]<<endl;

}
