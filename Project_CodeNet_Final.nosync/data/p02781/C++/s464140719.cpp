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
#include <locale>

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
typedef pair<long long int, pll> lpll;


const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 

long long int K,M,x,y,res=0,tmp=0,dp[200][5][2]={};
pll ba[200200];
string N;

int main(){
    cout << fixed << setprecision(18);
    cin>>N>>K;
    dp[0][1][0]=1;
    dp[0][1][1]=N[0]-'1';
    for(long long int i = 1; i < N.size(); i++){
        dp[i][1][1]+=9;
        if(N[i]=='0'){
            //0
            dp[i][1][0]+=dp[i-1][1][0];
            dp[i][1][1]+=dp[i-1][1][1];
            dp[i][2][0]+=dp[i-1][2][0];
            dp[i][2][1]+=dp[i-1][2][1];
            dp[i][3][0]+=dp[i-1][3][0];
            dp[i][3][1]+=dp[i-1][3][1];

            //!0
            dp[i][2][1]+=9*dp[i-1][1][1];
            dp[i][3][1]+=9*dp[i-1][2][1];
        }else{
            //0
            dp[i][1][1]+=dp[i-1][1][0];
            dp[i][1][1]+=dp[i-1][1][1];
            dp[i][2][1]+=dp[i-1][2][0];
            dp[i][2][1]+=dp[i-1][2][1];
            dp[i][3][1]+=dp[i-1][3][0];
            dp[i][3][1]+=dp[i-1][3][1];

            //max
            dp[i][2][0]+=dp[i-1][1][0];
            dp[i][3][0]+=dp[i-1][2][0];

            //!0
            dp[i][2][1]+=(N[i]-'1')*dp[i-1][1][0];
            dp[i][3][1]+=(N[i]-'1')*dp[i-1][2][0];

            dp[i][2][1]+=9*dp[i-1][1][1];
            dp[i][3][1]+=9*dp[i-1][2][1];
        }

    }
    cout<<dp[N.size()-1][K][1]+dp[N.size()-1][K][0]<<endl;
}


