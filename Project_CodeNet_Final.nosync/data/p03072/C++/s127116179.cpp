#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>h(n);
    rep(i,n) cin>>h.at(i);
    bool ok=true;
    int cnt=0;
    rep(i,n){ 
        rep(j,i){
            if(h.at(i)>=h.at(j)) ok=true;
            else {
                ok=false;
                break;
            }
        }
        if(ok) cnt+=1;
    }
    cout<<cnt<<endl;
}