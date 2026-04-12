#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> G[9];
int ans = 0;

void countPass(vector<bool> visit,int x){
    visit[x] = true;
    if(all_of(visit.begin()+1,visit.end(),[](bool b){return b;})) ans ++;
    for(int i = 0;i < G[x].size();i ++){
        if(!visit[G[x][i]]) countPass(visit,G[x][i]);
    }

}

int main(){
    int n,m,x=1;
    cin >> n >> m;
    vector<bool> visit(n+1);
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    countPass(visit,x);
    cout << ans << endl;

    return 0;
}