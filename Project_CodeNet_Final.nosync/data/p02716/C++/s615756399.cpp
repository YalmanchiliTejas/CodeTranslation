#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf=1e18;

int main(){
    int N; cin >> N;
    ll a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    ll dp[N+1]={};
    dp[1]=max(a[1],a[0]);
    ll tmp=a[0];
    for(int i=2;i<N;i++){
        if(i%2==1){
            tmp+=a[i-1];
            dp[i]=max(dp[i-2]+a[i],tmp);
        }else{
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }
    }
    cout << dp[N-1] << endl;
}