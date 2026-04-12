#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_set>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
using namespace std;
int n;
ll dp[3005][3005];
ll arr[3005];


int main(){
    AC
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        dp[i][i] = arr[i];
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            int end = j+i-1;
            dp[j][end] = max(arr[end]-dp[j][end-1], arr[j]-dp[j+1][end]);
        }
    }

    cout<<dp[0][n-1]<<endl;
}