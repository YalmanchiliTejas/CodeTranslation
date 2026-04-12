#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
int arr[3005];
int dp[3005][3005][2];
const int def = LLONG_MAX;
int maximumdiff(int arr[], int i, int j, int turn){
    if(i>j){
        return 0;
    }
    if(dp[i][j][turn]!=-1){
        return dp[i][j][turn];
    }
    if(turn==1){
        return dp[i][j][turn]= max(arr[i]+ maximumdiff(arr,i+1,j,0), arr[j]+maximumdiff(arr,i,j-1, 0));
    }
    else{
        return dp[i][j][turn]=min(maximumdiff(arr,i+1,j, 1),  maximumdiff(arr,i, j-1,1)) ;
    }
}
 
signed main () {
    clock_t beg = clock();
    // cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif 
    int a;
    cin>>a;
    int sum=0;
    int arr[a];
    for(int i=0;i<a;i++){
        cin >>arr[i];
        sum+=arr[i];
    }
    for(int i=0;i<a;++i){
        for(int j=0;j<a;++j){
            for(int turn=0;turn<=1;turn++){
                dp[i][j][turn]=-1;
            }
        }
    }

    int x= maximumdiff(arr,0,a-1,1);
    // cout<<x<<" ";
    int y = sum-x;
    cout<<x-y<<endl;
    // int mod = 1000000000 +7;
    // at any state we have no ofheads
    // int s =     
    return 0;
}
