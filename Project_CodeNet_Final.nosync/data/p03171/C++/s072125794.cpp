#include <bits/stdc++.h>
using namespace std;

vector<long long int> a;
vector<vector<long long int>> dp;

long long int f(int left, int right){
    if(dp[left][right] != 0) return dp[left][right];
    if(left == right)        return dp[left][right] = a[left];

    return dp[left][right] = max(a[left]  - f(left+1, right  ), 
                                 a[right] - f(left,   right-1));
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    dp.resize(n, vector<long long int>(n));

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << f(0,n-1) << endl;
    return 0;
}