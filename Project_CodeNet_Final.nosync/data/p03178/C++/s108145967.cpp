#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> P;
typedef pair<ll,pair<ll,ll> > p;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
static const int MAX_SIZE = 1 << 17; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5

ll dp[2][11000][110];

int main(){
    int n,nx;
    string K;
    int D;
    cin>>K>>D;
    n=K.size();
    dp[0][0][0]=1;
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<D;k++){
                if(i==0){
                    nx=K[j-1]-'0';
                    for(int l=0;l<nx;l++){
                        dp[1][j][(k+l)%D]+=dp[i][j-1][k];
                        dp[1][j][(k+l)%D]%=MOD;
                    }
                    dp[0][j][(k+nx)%D]+=dp[0][j-1][k];
                }else{
                    for(int l=0;l<10;l++){
                        dp[1][j][(k+l)%D]+=dp[1][j-1][k];
                        dp[1][j][(k+l)%D]%=MOD;
                    }
                }
            }
        }
    }
    if(dp[0][n][0]+dp[1][n][0]==0) cout<<MOD-1<<endl;
    else cout<<(dp[0][n][0]+dp[1][n][0]-1)%MOD<<endl;
}

