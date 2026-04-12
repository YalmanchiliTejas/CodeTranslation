#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const ll LNF = __LONG_LONG_MAX__;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
        sum = sum%MOD;
    }
    ll out=0;
    for(int i=0;i<N;i++){
        sum -= A[i]; if(sum<0) sum += MOD;
        out += A[i]*sum;
        out = out%MOD;
    }
    cout << out << endl;
    return 0;
}
