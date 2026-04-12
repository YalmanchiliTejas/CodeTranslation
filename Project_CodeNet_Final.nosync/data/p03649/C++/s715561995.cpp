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

long long int N,M,K,H,W,res=0,A[300000]={},B[300030]={},zero=0;
//今見ている番号＋今どの段階か(なにも飛ばしていない、１つ飛ばした、２つ飛ばした)＋奇数かどうか
long long int memo[1000400]={};
bool used[122345]={};
vector<long long int>positive,negative;

string S[100],T;



vector<long long int>output;

int main()
{
    cout << fixed << setprecision(18);
    cin>>N;
    
    for(long long int i = 0; i < N; i++){
        cin>>A[i];
    }
    bool key=true;
    while(key){
        for(long long int i = 0; i < N; i++){
            sort(A,A+N,greater<long long int>());
            for(long long int j = 0; j < N; j++){
                if(A[j]/N>0){
                    for(long long int k = 0; k < N; k++){
                        if(j!=k){
                            A[k]+=A[j]/N;
                        }
                    }
                }
                res+=A[j]/N;
                A[j]%=N;
            }
        }
        key=false;
        for(long long int i = 0; i < N; i++){
            if(A[i]>=N){key=true;}
        }
    }
    cout<<res<<endl;
}
