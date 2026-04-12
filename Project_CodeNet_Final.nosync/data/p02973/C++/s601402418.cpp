#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n) cin>>v[i];
    deque<int> di;
    rep(i,n){
        int id = lower_bound(di.begin(),di.end(),v[i]) - di.begin();
        if(id==0) di.push_front(v[i]);
        else di[id-1]=v[i];
    }
    cout<<di.size()<<endl;
    return 0;
}