#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    long long MOD = 1000000007;

    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for(int i=0;i<N;i++){
        cin >> A.at(i);
        sum += A.at(i);
        sum %= MOD;
    }

    long long res = 0;
    for(int i=0;i<N;i++){
        sum -= A.at(i);
        if(sum<0) sum += MOD;
        res += A.at(i) * sum;
        res %= MOD;
    }
    cout << res << endl;
}