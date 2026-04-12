#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long long n, k, ans = 0;
    cin >> n >> k;
    for(int i = k + 1; i <= n; i++){
            ans += (n / i) * (i - k) + max(0ll, n % i - k + 1);
    }
    if(k == 0){
        ans -= n;
    }
    
    cout << ans << endl;
    return 0;
}