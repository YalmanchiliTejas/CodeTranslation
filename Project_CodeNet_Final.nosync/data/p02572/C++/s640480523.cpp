#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    long long ans;
    long long w=1000000007;
    long long one=0,two=0;
    for(int i=0; i<N; i++){
        one=one+(A.at(i))%w;
        two=two+(A.at(i)*A.at(i))%w;
        one=one%w; 
        two=two%w;
    }
    ans=(one*one-two)%w;
    ans=ans*(w+1)/2;
    ans=ans%w;

    cout << ans << endl;
}

    
