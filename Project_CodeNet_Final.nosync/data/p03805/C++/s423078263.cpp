#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    int N, M;
    cin>>N>>M;
    int edge[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            edge[i][j] = 0;
        }
    }
    int a, b;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        a--;
        b--;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    vector<int> node;
    for(int i=0;i<N;++i){
        node.push_back(i);
    }
    int ans = 0;
    bool ok;
    do {
        ok = true;
        for(int i=0;i<N-1;++i){
            if(edge[node[i]][node[i+1]]==0) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(node.begin()+1, node.end()));
    cout<<ans<<endl;
}

