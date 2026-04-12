#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    long long N;cin>>N;
    long long A[N];
    long long sum=0;
    for(long long i=0;i<N;i++){
        cin>>A[i];
    //    sum+=A[i]; // この段階では加算しない
    }
    long long ans=0;
    for(long long i=0;i<N-1;i++){
        sum=(sum+A[i])%1000000007; // この段階で加算し，modを取る
        ans+=sum*A[i+1]%1000000007; // sumに，いま加えた要素の次の要素を掛け，ansに加算する
    }
    cout<<ans%1000000007<<endl;
    return 0;
}
