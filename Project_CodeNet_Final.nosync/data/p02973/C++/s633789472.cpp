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

long long int N,M,A[200030],L[200200],R[202000],sum[200200]={},res=0;
long long int dp[10005]={};



//最長単調増加列,0-indexed,要素数Nと配列a
class LIS{
    public:
	const long long int INF=5000000000000000000;
	long long int LIS_Do(long long int N,long long int a[]){
		long long int LIS_table[250005];
		long long int LIS_start=250000,now=LIS_start,ng=now,ok=now+1,mid;
		for(int i=0;i<=LIS_start;i++){
			LIS_table[i]=INF;
		}
		for(int i=0;i<N;i++){
			ng=now;
			ok=LIS_start+1;
			
			while(ok-ng>1){
				mid=(ng+ok)/2;
				if(LIS_table[mid]<a[i]){
					ng=mid;
				}else{ok=mid;}
			}
			
			LIS_table[ng]=a[i];
			if(ng==now){
				now--;
			}
			
		}
		for(int i=LIS_start;i<=now;i++){
			cout<<LIS_table[i]<<endl;
		}
		return LIS_start-now;
	}
    
};

int main()
{
    cout << fixed << setprecision(18);
    cin>>N;
    for(long long int i = 0; i < N; i++){
        cin>>A[i];
    }
    LIS lis;
    cout<<lis.LIS_Do(N,A)<<endl;
    
}
