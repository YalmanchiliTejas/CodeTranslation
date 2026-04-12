#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    map<int, vector<int>> graph;
    int l, r;
    for (int i=0;i<m;i++){
        cin >> l >> r;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }

    vector<int> nodes;
    for (int i=2;i<=n;i++){
        nodes.push_back(i);
    }

    int acc = 0;
    do {
        auto temp = nodes;
        temp.insert(temp.begin(), 1);
        bool flag = true;
        for (int i=0;i<n-1;i++){
            if (find(graph[temp[i]].begin(), graph[temp[i]].end(), temp[i+1]) == graph[temp[i]].end()){
                flag = false;
                break;
            }
        }
        if (flag){
            acc++;
        }
    }while(next_permutation(nodes.begin(), nodes.end()));
    cout << acc << endl;
    return 0;
}