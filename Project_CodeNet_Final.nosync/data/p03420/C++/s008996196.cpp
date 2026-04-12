#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    for(long long int b=k+1;b<=n;++b){
        long long int nn = (n+b-1)/b * b;
        ans += (nn / b) * (b-k);
        if(nn > n && (n+1)%b >= k)ans -= (nn - n - (k == 0 ? 0 : 1));
        else if(nn > n + 1 && (nn-1)%b >= k)ans -= (b-k);
    }

    cout << ans << endl;

    return 0;
}
