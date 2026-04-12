#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    int A[200000];
    int mod = 1000000007;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }
 
    long ans = 0;
 
    //i について全探索する
    for (int i = 0; i < N; i++)
    {
        //A[i+1] ... A[N] の値を更新する
        sum -= A[i];
        if (sum < 0) sum += mod;
 
        ans = (ans +A[i] * sum) % mod;

    }
 
    cout << ans << endl;
}