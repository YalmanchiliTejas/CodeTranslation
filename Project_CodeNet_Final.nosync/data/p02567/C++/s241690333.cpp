#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define ll long long
void view(vector<int> &arr){
    for (auto x:arr) cout<<x<<" ";
    cout<<endl;
}

int op(int a,int b){
    return max(a,b);
}
int e(){
    return -1000000000;
}

int M;
bool f(int x){
    return x<M;
}

int main(){
    int N,Q;
    cin>>N>>Q;
    vector<int> A(N);
    REP(i,N) cin>>A[i];
    segtree<int,op,e> SEG(A);

    REP(q,Q){
        int T;
        cin>>T;
        if (T==1){
            int X,V;
            cin>>X>>V;
            X--;
            SEG.set(X,V);
        }else if (T==2){
            int L,R;
            cin>>L>>R;
            L--;
            cout<<SEG.prod(L,R)<<endl;
        }else if (T==3){
            int X;
            cin>>X>>M;
            int res=SEG.max_right<f>(X-1)+1;
            cout<<res<<endl;
        }
    }

}