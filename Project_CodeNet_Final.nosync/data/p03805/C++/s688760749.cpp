#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

long long PRIME = 1e9 + 7;
using namespace std;

vector<vector<int>> E;

int search(int N, int node, bool passed[8], int prev){
    passed[node - 1] = true;

    bool check = true;
    for(int i = 0; i < N; ++i){
        check = check & passed[i];
    }
    if(check){
        passed[node - 1] = false;
        return 1;
    }

    int count = 0;
    for(int next : E[node]){
        if(passed[next - 1]){
            continue;
        }

        count += search(N, next, passed, node);
    }
    passed[node - 1] = false;

    return count;
}


int main(){ 
    long long N, M;
    cin >> N >> M;

    E.resize(N+1);
    int a, b;

    for(int i = 0; i < M; ++i){
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    bool passed[8];
    for(int i = 0; i < 8; ++i){
        passed[i] = false;
    }

    cout << search(N, 1, passed, -1);
}

