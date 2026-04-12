#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    long long ans = 0;
    if(N % 2 == 0){
        for(int i = 0; i < N; i++){
            if(i < N / 2){
                if(i == N / 2 - 1) ans -= A[i];
                else ans -= 2*A[i];
            }
            else{
                if(i == N / 2) ans += A[i];
                else ans += 2 * A[i];
            }
        }
        cout << ans << endl;
        return 0;
    }
    long long res = 0, res2 = 0;
    for(int i = 0; i < N; i++){
        if(i <= N / 2 - 1) {
            res -= 2 * A[i];
            res2 += 2* A[N - 1 - i];
        }
        else{
            if(i == N / 2 || i == N / 2 + 1){
                res += A[i];
                res2 -= A[N - 1 - i];
            }
            else{
                res += A[i] * 2;
                res2 -= 2 * A[N - 1 - i];
            }
        }
    }
    cout << max(res2, res) << endl;
}