#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FOR1(i, a, b, flag) for(int i=a; i<b && flag; i++)
typedef long long ll;

int c=1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    string k;
    getline(cin, k);
    int d;
    cin>>d;
    int n=k.size();
    int dp[n+1][d];
    memset(dp, 0, sizeof(int)*(n+1)*d);
    dp[n][0]=1;
    FOR(i1, 0, 10){
        dp[n-1][i1%d]++;
    }
    
    for(int i1=n-2; i1>0; i1--){
        FOR(i2, 0, 10){
            FOR(i3, 0, d){
                dp[i1][(i2+i3)%d]+=dp[i1+1][i3];
                dp[i1][(i2+i3)%d]%=c;
            }
        }
    }
    // FOR(i1, 0, )
    int tillnow=0;
    int ans=0;
    for(int i1=0; i1<n; i1++){
        int dig=k[i1]-'0';
        FOR(i2, 0, dig){
            ans=(ans+dp[i1+1][(d-((tillnow+i2)%d))%d])%c;
        }
        tillnow=(tillnow+dig)%d;
    }
    if(tillnow==0){
        ans++;
        ans%=c;
    }
    
    cout<<((ans>=1)?ans-1:c+ans-1)<<endl;
    return 0;
}