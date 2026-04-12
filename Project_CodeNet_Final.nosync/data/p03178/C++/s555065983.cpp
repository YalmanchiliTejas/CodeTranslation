#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string arr;
const int mod = 1e9+7, q =  1e5+5;
ll dp[q][150][2];

ll getsum(int ind, int n, int sum, bool flag, int d){
    if(ind>=n){return sum==0;}
    int limit=9;
    if(!flag) limit= arr[ind]-'0';
    //flag=true means earlier ther is some smaller digit used so we can take till 9 this time;
    if(dp[ind][sum][flag]!=-1) return dp[ind][sum][flag];
    
    ll res=0;
    for(int i=0;i<=limit;i++){
        if(flag || i<limit)
            res= (res + getsum(ind+1, n, (sum + i)%d, true,  d))%mod;

        else
            res= (res + getsum(ind+1, n, (sum + i)%d, false, d))%mod;
    }
    return dp[ind][sum][flag]= res;
}

int main(){
    // int t;cin>>t;
    // while(t--){
        // ll x, y; cin >> x >> y;
        string b; cin>>b;
        arr = b;
        int d; cin>>d;
        for(int i=0;i<b.size();i++)for(int j=0;j<150;j++)for(int k=0;k<2;k++) 
            dp[i][j][k]=-1;
        
        // for(int i=0;i<b.size();i++) arr[i]=b[i]-'0';
        ll right=getsum(0, b.size(), 0, 0, d);
        cout << (right - 1 + mod)%mod << endl;
    // }
}