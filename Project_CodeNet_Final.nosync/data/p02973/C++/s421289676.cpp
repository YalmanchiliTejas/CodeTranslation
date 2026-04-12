#include <bits/stdc++.h>

using namespace std;

int N;
int BIT[100005];
vector<int> cmp;
int arr[100005];
int dp[100005];

int getidx(int n){
    return lower_bound(cmp.begin(), cmp.end(), n) - cmp.begin() + 1;
}

void upd(int n, int v){
    n = getidx(-n);
    for(int i = n; i<=N; i+=i&-i){
        BIT[i] = max(BIT[i], v);
    }
}

int query(int n){
    int s = 0;
    n = getidx(-n);
    for(int i = n; i>0; i-=i&-i){
        s = max(BIT[i], s);
    }
    return s;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
        cmp.push_back(-arr[i]);
    }
    sort(cmp.begin(), cmp.end());
    //reverse(cmp.begin(), cmp.end());
    int ans = 0;
    for(int i = 1; i<=N; i++){
        dp[i] = query(arr[i]) + 1;
        upd(arr[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
