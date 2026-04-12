#include <bits/stdc++.h>
using namespace std;
string N;int K,n;
int nCr(int n,int r){
    if(r==1)return n;
    if(r==2)return n*(n-1)/2;
    if(r==3)return n*(n-1)*(n-2)/6;
    return 0;
}
int dp(int i,int k,bool s){
    if(k==0)return 1;
    else if(i==n)return 0;
    if(s)return nCr(n-i,k)*pow(9,k);
    else {
        if(N[i]=='0')return dp(i+1,k,0);
        else return dp(i+1,k,1)+dp(i+1,k-1,1)*(N[i]-'1')+dp(i+1,k-1,0);
    }
}
int main(){
    cin>>N>>K;
    n=N.size();
    cout<<dp(0,K,0)<<endl;
}
