#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a,b,N,K,cunt;                                                 
int main(){
    cin>>N>>K;

    if(K){
        for(b=K+1;b<=N;b++)
            cunt+=(N/b)*max(0ll,b-K)+max(0ll,N%b+1-K);
    }
    else
        cunt=N*N;
    cout<<cunt<<"\n";
    return 0;
}
