#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<set<int>> G(10);
int ans=0;
void per(int s,set<int> S){
    if(S.empty())ans++;
    for(auto itr=S.begin();itr!=S.end();itr++){
        if(G[s].find(*itr)==G[s].end())continue;
        set<int> T=S;
        T.erase(*itr);
        per(*itr,T);
    }
}

int main(){
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        G[a].insert(b);
        G[b].insert(a);
    }
    set<int> S;
    for(int i=2;i<=N;i++){
        S.insert(i);
    }
    per(1,S);
    cout<<ans<<endl;
    return 0;
}