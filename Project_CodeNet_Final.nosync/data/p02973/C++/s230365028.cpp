#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved
int main(){
    int n;
    cin>>n;
    vector<long long>A(n);
    rep(i,n){
        cin>>A[i];
    }
    rep(i,n)A[i]=-A[i];
    multiset<long long>color;
    color.emplace(1);
    rep(i,n){
    auto it=color.upper_bound(A[i]);
        if(it!=color.end()){
        color.erase(it);
        color.emplace(A[i]);
        }
        else{
        color.emplace(A[i]);
        }
    }
    cout<<color.size()<<endl;
    
    return 0;

}
/*


*/
