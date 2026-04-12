#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

const int INF = 10;
int dp[100100];

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= -1;
    }

    fill(dp, dp + n, INF);
    for(int i = 0; i < n; i++){
        *upper_bound(dp, dp + n, a[i]) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp + n, INF) - dp);

    return 0;
}