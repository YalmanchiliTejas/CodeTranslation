#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    vll A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    
    if(N%2==0){
        vvll dp(N/2,vll(2,0));//奇数にシフト
        for(int i=0;i<N/2;i++){
            if(i==0){
                dp[0][0]=A[0];
                dp[0][1]=A[1];
            }else{
                dp[i][0]=A[i*2]+dp[i-1][0];
                dp[i][1]=max(dp[i-1][1],dp[i-1][0])+A[2*i+1];
            }
        }
        cout<<max(dp[N/2-1][0],dp[N/2-1][1])<<endl;
    }else{
        vvll dp(N/2,vll(3,0));
        for(int i=0;i<N/2;i++){
            if(i==0){
                dp[0][0]=A[0];
                dp[0][1]=A[1];
                dp[0][2]=A[2];
            }else{
                dp[i][0]=A[i*2]+dp[i-1][0];
                dp[i][1]=max(dp[i-1][1],dp[i-1][0])+A[2*i+1];
                dp[i][2]=max(dp[i-1][2],dp[i-1][1])+A[i*2+2];
            }
        }
        cout<<max(dp[N/2-1][2],max(dp[N/2-1][0],dp[N/2-1][1]))<<endl;
    }
    
    return 0;
}
