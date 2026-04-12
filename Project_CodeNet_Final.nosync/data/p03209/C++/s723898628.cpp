#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
int main(){
    cin>>n>>m;
    vector<ll> sumP(n+1),sumLayer(n+1);
    sumP.at(0)=1,sumLayer.at(0)=1;
    for(int i=1;i<n+1;i++){
        sumP.at(i)=2*sumP.at(i-1)+1;
        sumLayer.at(i)=2*sumLayer.at(i-1)+3;
    }
    while(n){
        if(m==1) {
            m=0;
            break;
        }
        else if(m==sumLayer.at(n)){
            ans+=sumP.at(n);
            m=0;
            break;
        }
        else if(m-2==sumLayer.at(n-1)){
            ans+=sumP.at(n-1)+1;
            m=0;
            break;
        }
        else if(m-2<sumLayer.at(n-1)){
            m--;
            n--;
        }
        else if(m-2>sumLayer.at(n-1)){
            ans+=sumP.at(n-1)+1;
            m-=(sumLayer.at(n-1)+2);
            n--;
        }
    }
    ans+=m;
    cout<<ans<<endl;
}
