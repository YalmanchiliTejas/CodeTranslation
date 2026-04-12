#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;    
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

struct Node
{
    vector<int> next;
};
vector<Node> node;
ll ans;

void dfs(vector<int> search, int index){

    if(search[index] == 1){
        return ;
    }
    else{
        search[index] = 1;
    }

    bool flag = true;
    for(int i = 0; i < search.size(); i++){
        if(search[i] == 0) flag = false;
    }
    if(flag) ans++;

    for(int i = 0; i < node[index].next.size(); i++){
        dfs(search, node[index].next[i]);
    }

}



int main(){

    int N, M;
    cin >> N >> M;

    node.resize(N+1);
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        node[a].next.push_back(b);
        node[b].next.push_back(a);
    }

    vector<int> v(N+1);
    v[0] = 1;

    dfs(v, 1);
    cout << ans << endl;


}