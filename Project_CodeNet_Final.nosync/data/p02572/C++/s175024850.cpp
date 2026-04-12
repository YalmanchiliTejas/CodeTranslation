#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
 
int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll total = 0;
    for(int i=0; i<N; i++) {
        int a;
        cin >> a;
        A[i] = a;
        total += a;
    }
 
    ll sum = 0;
    for(int i=0; i<N-1; i++) {
        total -= A[i];
        sum += (A[i] * (total % (1000000000+7)));
        sum %= 1000000000+7;
    }
    cout << sum % (1000000000+7) << endl;
}