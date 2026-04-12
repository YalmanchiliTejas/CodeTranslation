#include<bits/stdc++.h>
using namespace std;
#define rep(n,k) for(int i = (int)n;i<k;i++)
using Int =long long int;
using Graph =vector<vector<int>>;
int main(){
    int N;cin>>N;
    Int sum1=0;
    vector<Int>num(N);
    rep(0,N){
        Int a;
        cin>>a;
        num.at(i)=a;
        sum1+=a;
    }
    Int sum2=0;
    //  1000000007
    rep(0,N){
        sum1 -=num.at(i);
        sum2 += (num.at(i)*(sum1%1000000007));
        sum2= sum2%1000000007;

        
    }
    cout<<sum2<<endl;

}