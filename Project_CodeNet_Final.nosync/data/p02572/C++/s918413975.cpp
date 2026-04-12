#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N; cin>>N;
    vec_int A(N);
    rep(i,N)cin>>A.at(i);
    int MOD = pow(10,9)+7;

    vec_int A_sum(N);
    A_sum.at(N-1) = A.at(N-1);
    for(int i=N-2;i>=0;i--){
        A_sum.at(i) = (A_sum.at(i+1) + A.at(i))%MOD;
    }

    int output = 0;

    for(int i=0;i<N-1;i++){
        output = (output + A.at(i) * A_sum.at(i+1))%MOD;
    }
    cout<<output%MOD<<endl;





    return 0;
}