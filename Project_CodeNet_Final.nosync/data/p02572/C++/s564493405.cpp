#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int mod = 1000000007;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        //cout<<sum<<" without"<<endl;
        sum %= mod;
        //cout<<sum<<" with"<<endl;
    }
 
    long long ans = 0;
 
    //Search for all i
    for (int i = 0; i < N; i++)
    {
        //Update the values of A[i+1] ... A[N]
        sum -= A[i];
        if (sum < 0) sum += mod;
 
        ans += A[i] * sum;
        ans %= mod;
    }
 
    cout << ans << endl;
}