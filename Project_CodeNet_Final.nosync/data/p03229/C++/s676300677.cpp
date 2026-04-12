#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long ans = 0;
    if(n % 2 == 0){
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                if(i == n / 2 - 1) ans -= A[i];
                else ans -= A[i] * 2;
            }else{
                if(i == n / 2) ans += A[i];
                else ans += A[i] * 2;
            }
        }
    }else{
        for(int i = 0; i < n; i++){
            if(i <= n / 2){
                if(i < n / 2 - 1) ans -= A[i] * 2;
                else ans -= A[i];
            }else{
                ans += A[i] * 2;
            }
        }

        long long t = 0;
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                t -= A[i] * 2;
            }else{
                if(i < n / 2 + 2){
                    t += A[i];
                }else{
                    t += A[i] * 2;
                }
            }
        }
        ans = max(ans, t);
    }

    cout << ans << endl;

    return 0;
}