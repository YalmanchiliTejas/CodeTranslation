#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    long long N,X,M;
    cin >> N >> X >> M;
    long long ps[2*M+1];
    ps[0]=0;
    long long patt=X;
    long long prev=X;
    ps[1]=X;
    long long basic;
    long long patlength;
    unordered_map<int,int>ok;
    ok[X]=1;
    long long uwu;
    for(int i=2;i<=2*M;i++){
        prev=(prev*prev)%M;
        if(ok[prev]){
            basic=ok[prev];
            patlength=i-ok[prev];
            uwu=i-1;
            break;
        }
        ok[prev]=i;
        ps[i]=ps[i-1]+prev;
        patt+=prev;
    }
    long long ans=ps[basic-1];
    N-=(basic-1);
    ans+=(N/patlength)*(ps[uwu]-ps[basic-1]);
    ans+=ps[basic-1+N%patlength]-ps[basic-1];
    cout<<ans;
}