#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    long long w=1000000007;
    long long ans=0;
    vector<long long> sum(N+1);
    for(int i=0; i<N; i++){
       sum.at(i+1)=(sum.at(i)+A.at(i))%w;
    }
    for(int i=0; i<N-1; i++){
        ans=ans+(A.at(i+1)*sum.at(i+1))%w;
        ans=ans%w;
    }
    cout << ans << endl;
}
