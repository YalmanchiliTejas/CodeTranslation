//Subhash Suman
//Date: 14/02/19 ; Day: Thursday ; Time: 07::11::03 
//Description : 

#include<bits/stdc++.h>
#define ll long long int
#define MAX INT_MAX
#define MIN INT_MIN
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>

using namespace std;
const int N = 3005;
ll arr[N];
ll dp[N][N];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        dp[i][i] = arr[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            dp[j][j+i] = max(arr[j]-dp[j+1][j+i],arr[j+i]-dp[j][j+i-1]);
        }
    }
    cout<<dp[0][n-1]<<'\n';
    return 0;
}