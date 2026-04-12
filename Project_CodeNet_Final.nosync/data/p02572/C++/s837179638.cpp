#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin>>A[i];
    ll NUM=1000000007;

    ll sum_A[N];
    rep(i, N){
        int k=N-i-1;
        if(k==N-1) sum_A[k]=A[k]%NUM;
        else sum_A[k]=(sum_A[k+1]+A[k])%NUM;
    }

    ll ans=0;
    for(int i=0; i<N-1; i++){
        ans+=(A[i]*sum_A[i+1])%NUM;
    }

    cout<<ans%NUM<<endl;
    return 0;
}