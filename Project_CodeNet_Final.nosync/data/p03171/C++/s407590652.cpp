#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 3005;
ll a[N];
ll dp[N][N];

//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);  cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }

    for(int j = 0 ; j < n ; j++){
        for(int i = j ; i >= 0 ; i--){
            if(i == j){
                dp[i][j] = a[i];
            }else{

                dp[i][j] = max(a[j] - dp[i][j-1] , a[i] - dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}