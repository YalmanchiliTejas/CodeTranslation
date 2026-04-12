#include <bits/stdc++.h>
using namespace std;

long long n, k, ans;

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        if(i-k >= 0){
            ans += n/i*(i-k);
            if(n % i >= k ){
                if(k != 0)  ans += n % i - k + 1;
                else ans += n % i;
            }
        }
    }

    cout << ans << endl;
}