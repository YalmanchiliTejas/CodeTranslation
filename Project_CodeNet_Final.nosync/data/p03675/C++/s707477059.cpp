#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    
    deque<int> deq;
    rep(i,n){
        if(i%2==0)deq.push_front(v[i]);
        else deq.push_back(v[i]);
    }
    if(n%2==0)reverse(all(deq));
    
    rep(i,deq.size()){
        if(i)cout<<" ";
        cout<<deq[i];
    }
    cout<<endl;
}