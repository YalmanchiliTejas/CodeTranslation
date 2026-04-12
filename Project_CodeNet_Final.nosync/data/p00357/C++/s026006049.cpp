#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define V vector
#define VI vector<int>
#define VVI vector<vector<int>>

using namespace std;

int main(void){
    int N;
    cin>>N;
    VI d(N);
    rep(i,N)cin>>d[i];
    VI G(N-1),R(N-1);
    G[0]=d[0],R[N-2]=d[N-1];
    for(int i=0;i<N-2;i++){
        G[i+1]=max(d[i+1],G[i]-10);
    }
    for(int i=N-2;i>=1;i--){
        R[i-1]=max(d[i],R[i]-10);
    }
    sort(G.begin(),G.end());
    sort(R.begin(),R.end());
    if(G[0]>=10&&R[0]>=10){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;

}


