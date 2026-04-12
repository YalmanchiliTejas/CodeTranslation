#include <bits/stdc++.h>
using namespace std;

long bfs(long d,long X,vector<long> &P,vector<long> &L){
    if(d==0) return X;
    
    if(X==2*L.at(d-1)+3) return P.at(d);
    if(L.at(d-1)+2<=X && X<=2*L.at(d-1)+2) return P.at(d-1)+1+bfs(d-1,X-L.at(d-1)-2,P,L);
    if(1<=X && X<=L.at(d-1)+1) return bfs(d-1,X-1,P,L);
    return 0;
}
int main(){
    long N,X;
    cin>>N>>X;
    vector<long> P(N+1),L(N+1);
    P.at(0)=1;
    L.at(0)=1;
    for(int i=0;i<N;i++){
        P.at(i+1)=2*P.at(i)+1;
        L.at(i+1)=2*L.at(i)+3;
    }
    
    cout<<bfs(N,X,P,L)<<endl;
}