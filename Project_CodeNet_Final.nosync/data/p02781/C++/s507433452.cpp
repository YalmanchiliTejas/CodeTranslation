#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string arr;
const int q =  1e5+5;
ll dp[q][150][2];
int d;
ll getsum(int ind, int n, int sum, bool flag, int use){
    if(ind>=n) return use==d;
    // {if(d==0) return 1;return 0;} 
    int limit=9;
    if(!flag) limit= arr[ind]-'0';
    
    if(dp[ind][use][flag]!=-1) return dp[ind][use][flag];
    
    ll res=0;
    for(int i=0;i<=limit;i++){
        // if(i!=0)use++;
            res+= getsum(ind+1, n, 1, flag || i<limit,  use+(i!=0));
            
    }
    return dp[ind][use][flag]= res;
}

int main(){
    // int t;cin>>t;
    // while(t--){
        // ll x, y; cin >> x >> y;
        cin>>arr;
         cin>>d;
        for(int i=0;i<arr.size();i++)for(int j=0;j<150;j++)for(int k=0;k<2;k++) 
            dp[i][j][k]=-1;
        
        // for(int i=0;i<b.size();i++) arr[i]=b[i]-'0';
        ll right=getsum(0, arr.size(), 0, 0, 0);
        cout << right<< endl;
    // }
}