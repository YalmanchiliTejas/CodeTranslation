#include <iostream>
#include <vector>

using namespace std;

int N;

int dfs(const vector<int>* edges, vector<int> S, int node){
    if(S.size() == N) return 1;
    bool flag;
    int count = 0;
    for(int p : edges[node]){
        flag = false;
        for(int s : S){
            if(p == s){
                flag=true;
                break;
            }
        }
        // すでに辿ってきた
        if(flag) continue;
        else{
            S.push_back(p);
            count += dfs(edges, S, p);
            S.pop_back();
        }
    }
    return count;
}

int main()
{
    int M;
    cin >> N >> M;
    vector<int> edges[N];
    int a, b;
    for(int i=0;i<M;++i){
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int ans = dfs(edges, vector<int>(1), 0);

    cout << ans << endl;
}
