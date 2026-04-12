#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 

 
/*
ll gcds(ll a,ll b){
    if(a<b){
        swap(a,b);
    }
    ll r=a%b;
    if(r==0){
        return b;
    }
    while(r>0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
 
 
ll lcms(ll a,ll b){
    ll mmr=gcds(a,b);
    a=a/mmr;
    b=b/mmr;
    return a*b*mmr;
}
*/
 

int main(){
    string S;
    cin>>S;
    int tmp=0;
    if(S.at(0)!=S.at(1)){
        tmp=1;
        //cout<<"a";
    }
    if(S.at(0)!=S.at(2)){
        tmp=1;
    }
    if(S.at(1)!=S.at(2)){
        tmp=1;
    }

    if(tmp==1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}