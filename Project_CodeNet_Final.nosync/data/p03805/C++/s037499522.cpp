#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;

int N, M;
bool data[10][10] = {};
int way = 0;
array<bool, 10> arr;

void dfs(int now, array<bool, 10> a){
    a[now] = true;
    bool check = true;
    for(int i = 0; i < N; ++i){
        if(!a[i]){
            check = false;
        }
    }
    if(check){
        way++;
        return;
    }
    for(int i = 0; i < N; ++i){
        if(data[now][i] && !a[i]){
            dfs(i, a);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        data[a][b] = true;
        data[b][a] = true;
    }

    dfs(0, arr);
    cout << way << endl;

    return 0;
}