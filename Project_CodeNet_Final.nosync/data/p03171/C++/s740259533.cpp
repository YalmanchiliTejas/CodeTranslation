#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    int arr[N];
    long long dp[N][N];
    for (int i = 0 ; i < N ; i++)
        cin >> arr[i];
    for (int k = 0 ; k < N ; k++){
        for (int i = 0 ; i < N - k ; i++){
            int l = i , r = i + k;
            if (l == r){
                if (N & 1)//jika N ganjil maka giliran penambah
                    dp[l][l] = arr[l];
                else
                    dp[l][l] = -arr[l];
            }
            else if ((l + N - 1 - r & 1) == 0)//jika genap maka langkahnya penambah
                 dp[l][r] = max(dp[l + 1][r] + arr[l] , dp[l][r - 1] + arr[r]);
            else //giliran ganjil , giliran pengurang
                dp[l][r] = min(dp[l + 1][r] - arr[l] , dp[l][r - 1] - arr[r]);
        }
    }
    cout << dp[0][N - 1] << endl;
}
