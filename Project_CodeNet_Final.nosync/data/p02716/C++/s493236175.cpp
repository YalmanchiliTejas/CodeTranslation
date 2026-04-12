#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
typedef long long ll;
typedef long double ld;
using namespace std;

ll A[200010], dp[200010][2];

int main(void){
    int N;
    cin >> N;
    for(int i=0; i<N; ++i) cin >> A[i];
    dp[0][0]=A[0];
    dp[1][0]=A[1];
    if(N%2==0){
        for(int i=1; i*2<N; ++i){
            dp[i*2][0]=dp[i*2-2][0]+A[i*2];
            dp[i*2+1][0]=max(dp[i*2-2][0], dp[i*2-1][0])+A[i*2+1];
        }
        cout << max(dp[N-2][0], dp[N-1][0]) << endl;
    }
    else{
        dp[0][1]=A[0];
        dp[2][0]=A[2];
        dp[2][1]=dp[0][0]+A[2];
        for(int i=2; i*2<N; ++i){
            dp[i*2-1][0]=max(dp[i*2-4][1], dp[i*2-3][0])+A[i*2-1];
            dp[i*2][0]=max({dp[i*2-4][1], dp[i*2-3][0], dp[i*2-2][0]})+A[i*2];
            dp[i*2][1]=dp[i*2-2][1]+A[i*2];
        }
        cout << max({dp[N-3][1], dp[N-2][0], dp[N-1][0]}) << endl;
    }
    return 0;
}
