#include <bits/stdc++.h>
using namespace std;
int n;
long long x, t[51] = {1}, p[51] = {1};

long long dp(int n, long long x){
    if(n == 0){
        return x > 0 ? 1 : 0;
    }else if(x < t[n - 1] + 2){
        return dp(n - 1, x - 1);
    }else{
        return p[n - 1] + 1 + dp(n - 1, x - t[n - 1] - 2);
    }
}

int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        t[i] = t[i - 1] * 2 + 3;
        p[i] = p[i - 1] * 2 + 1;
    }
    cout << dp(n, x) << endl;
}
