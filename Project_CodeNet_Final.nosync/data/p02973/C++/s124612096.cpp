#include <bits/stdc++.h>
using namespace std;
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
    int N;
    cin>>N;
    vector<ll> v(N);
    rep(i,N) {
        cin>>v[i];
        v[i]*=-1;
    }
    vector<ll> s;
    rep(i,N){
        auto ite = upper_bound(s.begin(),s.end(),v[i]);
        if(ite==s.end()) s.push_back(v[i]);
        else{
            *ite=v[i];
        }
    }
    cout<<s.size()<<endl;
}