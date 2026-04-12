#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#define rep(i,N) for(int i=0; i<N;i++)
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long int> A(N);
    vector<long int> B(N-1);
    rep(i,N){
        cin>>A.at(i);
    }
    long int ans=0;
    B.at(0)=A.at(N-1);
    for(int i=1;i<N-1;i++){
        B.at(i)=B.at(i-1)+A.at(N-1-i);
        B.at(i)=B.at(i)%1000000007;
    }
    rep(i,N-1){
        ans+=A.at(i)*B.at(N-2-i)%1000000007;
    }
    cout<<ans%1000000007<<endl;



    return 0;
}