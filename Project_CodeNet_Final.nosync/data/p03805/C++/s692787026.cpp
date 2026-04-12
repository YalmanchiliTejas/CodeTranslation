#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=100100;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int N,M;
    ll ans=0;
    cin>>N>>M;
    vector<vector<int>> v(N);
    vector<int> p;
    for(int i=0;i<N;i++) p.push_back(i);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    do{
        if(p[0]!=0) break;
        ll cnt=0;
        for(int i=0;i<N-1;i++){
            for(int j=0;j<v[p[i]].size();j++){
                if(v[p[i]][j]==p[i+1]) cnt++;
            }
        }
        if(cnt==N-1) ans++;
    }while(next_permutation(p.begin(),p.end()));
    cout<<ans<<endl;
}