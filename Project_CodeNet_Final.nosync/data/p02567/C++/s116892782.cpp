#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

int segop(int a,int b){
    return max(a,b);
}

int sege(){
    return -1;
}

int segfn;
bool segf(int v){
    return v < segfn;
}

int main(){
    int N,Q;
    cin>>N>>Q;
    segtree<int,segop,sege> seg(N+1);
    for(int i=0;i<N;i++){
        int A;
        cin>>A;
        seg.set(i+1,A);
    }

    for(int i=0;i<Q;i++){
        int t,x,v;
        cin>>t>>x>>v;
        if(t==1){
            seg.set(x,v);
        }
        if(t==2){
            cout<<seg.prod(x,v+1)<<endl;
        }
        if(t==3){
            segfn=v;
            cout<<seg.max_right<segf>(x)<<endl;
        }
    }
}
