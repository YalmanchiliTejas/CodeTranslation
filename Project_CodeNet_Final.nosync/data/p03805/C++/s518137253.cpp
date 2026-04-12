#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N,M;cin>>N>>M;
    vector<set<int> > G(N);
    vector<int> v(N);
    FOR(i,0,N) v[i]=i;
    int a,b;
    FOR(i,0,M){
        cin>>a>>b;a--;b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    int res=0;
    do{
        bool f =true;
        FOR(i,0,N-1){
            if(G[v[i]].find(v[i+1])==G[v[i]].end())f=false; 
        }
        if(f) res++;
    }while(next_permutation(v.begin()+1,v.end()));
    cout << res << endl;
    return 0;
}