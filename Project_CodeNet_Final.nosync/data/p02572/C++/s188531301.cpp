#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    ll all=0;
    int mod = 1000000007;

    for(int i=0; i<N; i++){
        cin >> A.at(i);
        all+=A.at(i);
        all%=mod;
    }

    ll sum=0;

    for(int i=0; i<N; i++){
        all-=A.at(i);
        if(all<0){
            all+=mod;
        }
        sum+=A.at(i)*all;
        sum%=mod;
    }

    cout << sum << endl;
}