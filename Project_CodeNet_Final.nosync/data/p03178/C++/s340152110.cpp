#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<stack>
#include<tuple>
using namespace std;
#define INF 1100000000000
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

ll dp[11000][110][2];

int main(){
    int D;
    string K;
    cin>>K>>D;
    dp[0][0][0]=1;
    int N=(int)K.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++){
            for(int k=0;k<2;k++){

                if(k==0){
                    int a=K[i]-'0';
                    for(int l=0;l<a;l++){
                        dp[i+1][(j+l)%D][1]+=dp[i][j][k];
                        dp[i+1][(j+l)%D][1]%=MOD;
                    }
                    dp[i+1][(j+a)%D][0]+=dp[i][j][k];
                    dp[i+1][(j+a)%D][0]%=MOD;
                }else{
                    for(int l=0;l<=9;l++){
                        dp[i+1][(j+l)%D][k]+=dp[i][j][k];
                        dp[i+1][(j+l)%D][k]%=MOD;                        
                    }
                }

            }
        }
    }
    cout<<(dp[N][0][1] + dp[N][0][0] -1 +MOD)%MOD<<endl; 
}

