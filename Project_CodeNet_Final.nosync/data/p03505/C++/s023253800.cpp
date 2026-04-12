#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=998244353,MAX=1000001,INF=1<<30;

int main(){
    
    ll K,A,B;cin>>K>>A>>B;
    if(A<=B){
        if(K<=A) cout<<1<<endl;
        else cout<<-1<<endl;
    }else{
        if(K<=A) cout<<1<<endl;
        else{
            K-=A;
            ll need=(K+(A-B-1))/(A-B);
            cout<<need*2+1<<endl;
        }
    }
}
