#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    //freopen("input.txt","r",stdin);
    lli n;
    cin >> n;
    vector <lli> v(n);
    for(int i =0;i<n;i++)cin >> v[i];
    vector < vector <lli> > dp(n,vector <lli> (n));
    for(int l = n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r){
                dp[l][r] = v[l];
            }else{
                dp[l][r] = max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
            }
        }
    }
    cout << dp[0][n-1]<<endl;
}
