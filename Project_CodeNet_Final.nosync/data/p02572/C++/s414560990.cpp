#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
int N;
    cin >> N;
    vector<int> A(N);
    int mod = 1000000007;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        sum %= mod;//配列の全和を求める
    }
 
    long ans = 0;
 
    //i について全探索する
    for (int i = 0; i < N; i++)
    {
        //A[i+1] ... A[N] の値を更新する
        sum -= A[i];//A[i+1]-の和
        if (sum < 0) sum += mod;//もしA[i]を引くことでsumの値が負になった時はmodを足す
        ans += A[i] * sum;//A[i]*(A[i+1]-の和)
        ans %= mod;
    }
 
    cout << ans << endl;
}