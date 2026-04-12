#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<math.h>
#include<utility>
#include<climits>
#include <algorithm> 
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>


using namespace std; 

long long int func(vector<vector<long long int> > &dp,vector<long long int> &ar,long long int i,long long int j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j)
        return ar[i];
    if(i+1==j)
        return max(ar[i],ar[j]);
    long long int x = ar[i]+min(func(dp,ar,i+2,j),func(dp,ar,i+1,j-1));
    long long int y = ar[j]+min(func(dp,ar,i,j-2),func(dp,ar,i+1,j-1));
    dp[i][j] = max(x,y);
    // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    return max(x,y);
    // return max(,);
}



int main(){
    long long int n;
    cin>>n;
    vector<long long int> ar(n,0);
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        cin>>ar[i];
        sum+=ar[i];
    }
    vector<vector<long long int> > dp(n,vector<long long int>(n,-1));
    long long int ans = func(dp,ar,0,n-1);
    long long int y = sum-ans;
    ans = ans-y;
    cout<<ans;
}



