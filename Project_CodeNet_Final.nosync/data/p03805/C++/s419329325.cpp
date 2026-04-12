#include <iostream>
#include <vector>
using namespace std;

long long ans = 0;

void dfs(int v,vector<vector<int>> &map,int n,vector<bool> &seen)
{
    int i;
    bool flag = true;
    for(i = 0;i < n;++i){
        if(!seen.at(i)){
            flag = false;
            break;
        }
    }
    if(flag){
        ++ans;
        return;
    }
    for(int x:map.at(v)){
        if(seen.at(x)){
            continue;
        }else{
            seen.at(x) = true;
            dfs(x,map,n,seen);
            seen.at(x) = false;
        }
    }
    return;
}

int main()
{
    int n,m;
    int i,j;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    for(i = 0;i < m;++i){
        cin >> a.at(i) >> b.at(i);
    }
    vector<vector<int>> map(n);
    for(i = 0;i < m;++i){
        map.at(a.at(i)-1).push_back(b.at(i)-1);
        map.at(b.at(i)-1).push_back(a.at(i)-1);
    }
    vector<bool> seen(n,false);
    seen.at(0) = true;
    dfs(0,map,n,seen);
    cout << ans << endl;
    return 0;
}