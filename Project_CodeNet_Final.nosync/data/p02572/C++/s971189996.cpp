#include <fstream>
#include <iostream>

using namespace std;

int main(){
    int N,mod;
    long long ans=0, sum=0;
    cin>>N;
    long long A[N];
    mod = 1000000007;
    for (int i=0;i<N;i++) {
        cin >> A[i];
        sum+=A[i];
    }
    sum%=mod;
    for(int i=0;i<N;i++){
        sum-=A[i];
        if(sum<0){
            sum+=mod;
        }
        ans +=(sum*A[i]);
        ans%=mod;
    }
    cout<<ans<<endl;
}