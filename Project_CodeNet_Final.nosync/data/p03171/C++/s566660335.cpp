#include<bits/stdc++.h>
using namespace std;
using lint = long int;

int N;
lint res;
lint a[3010];
lint dp[3010][3010];
bool calced[3010][3010] = {0};


lint dequeue_calc(int l, int r){
    if(calced[l][r]) return dp[l][r];
    
    /*l,r範囲は未到達*/
    calced[l][r] = 1;  //到達報告
    if(l == r) return a[l];  //これは確定値

    if(!calced[l][r-1]) dp[l][r-1] = dequeue_calc(l, r-1);
    if(!calced[l+1][r]) dp[l+1][r] = dequeue_calc(l+1, r);

    return dp[l][r] = max(a[r]-dp[l][r-1], a[l]-dp[l+1][r]);
}


int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];

    res = dequeue_calc(1, N);
    cout << res << endl;
    return 0;
}
