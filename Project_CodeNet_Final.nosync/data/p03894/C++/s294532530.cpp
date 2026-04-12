#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,Q;
int A[111111],B[111111];

int latte[111111];

bool ex[111111];

signed main(){
    cin>>N>>Q;
    rep(i,Q)cin>>A[i]>>B[i],A[i]--,B[i]--;
    rep(i,N)latte[i]=i;

    int pos=0;
    rep(i,N){
        if(A[i]==pos)pos=B[i];
        else if(B[i]==pos)pos=A[i];
    }

    if(pos>0)ex[pos-1]=true;
    ex[pos]=true;
    if(pos+1<N)ex[pos+1]=true;

    rep(i,N)latte[i]=i;
    for(int i=Q-1;i>=0;i--){
        if(A[i]==pos)pos=B[i];
        else if(B[i]==pos)pos=A[i];

        swap(latte[A[i]],latte[B[i]]);


        if(pos>0)ex[latte[pos-1]]=true;
        ex[latte[pos]]=true;
        if(pos+1<N)ex[latte[pos+1]]=true;
    }

    cout<<accumulate(ex,ex+N,0ll)<<endl;
    return 0;
}
