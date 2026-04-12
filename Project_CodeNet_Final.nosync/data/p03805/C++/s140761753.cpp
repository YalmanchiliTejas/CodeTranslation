#include <iostream>
#include <vector>
using namespace std;
int n,m;
long long sum;
vector<int> G[8];

void solve(int now,bool* arrived){
    bool t_arrived[8];
    for(int i=0;i<n;i++)t_arrived[i]=arrived[i];
    t_arrived[now]=1;
    bool flag=1;
    for(int i=0;i<n;i++)if(!t_arrived[i])flag=0;
    if(flag) sum++;
    for(auto x: G[now])if(!t_arrived[x])solve(x,t_arrived);
}

int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool arrived[8];
    solve(0, arrived);
    cout<<sum<<endl;
}
