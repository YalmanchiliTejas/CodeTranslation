#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

int main(){
    int N,K;
    cin >> N >> K;
    LL ans=0;
    for(int i=K+1;i<=N;i++){
        ans+=N/i*(i-K);
        ans+=max(N-N/i*i-K+1,0);
    }
    if(K==0) ans-=N;
    cout << ans << endl;
    return 0;
}