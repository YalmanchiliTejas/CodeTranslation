#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T&a , T b){
    if(a<b){
        a=b; return true;
    }else{
        return false;
    }
}
template<class T> inline bool chmin(T&a , T b){
    if(a>b){
        a=b; return true;
    }else{
        return false;
    }
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll dp[3005][3005];

int main(){
    int n;
    cin >> n;
    int a[3005];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++) dp[i][i] = a[i];

    int cnt=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-cnt;j++){
            dp[j][j+cnt] = max(a[j]-dp[j+1][j+cnt], a[j+cnt]-dp[j][j+cnt-1]);
        }
        cnt++;
    }

    cout << dp[1][n] << endl;


}