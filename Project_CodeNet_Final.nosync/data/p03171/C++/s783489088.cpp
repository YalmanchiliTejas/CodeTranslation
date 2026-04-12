#include <iostream>
using namespace std;
#define ll long long int
ll a, sign, arr[3001], dp[3001][3001];
ll eval (ll l, ll r){
    if (l==r) dp[l][r]=sign*arr[l];
    if (dp[l][r]!=0) return dp[l][r];
    if ((l+((a-1)-r))%2==0){ //Taro's turn
        dp[l][r]=max(eval(l+1, r)+arr[l], eval(l, r-1)+arr[r]);
        return dp[l][r];
    }
    else { //Jiro's turn
        dp[l][r]=min(eval(l+1, r)-arr[l], eval(l, r-1)-arr[r]);
        return dp[l][r];
    }
}
int main(){
    cin>>a;
    if (a%2==0) sign=-1;
    else sign=1;
    for (ll i=0; i<a; i++) cin>>arr[i];
    cout<<eval(0, a-1)<<endl;
}