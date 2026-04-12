#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool find(std::vector<int> v, int i){
    bool found = (std::find(v.begin(), v.end(), i) != v.end());
    return found;
}

std::vector<int> copyVector(std::vector<int> v){
    std::vector<int> newV;
    for (int i=0; i<v.size(); i++){
        newV.push_back(v[i]);
    }
    return newV;
}

int main(){
    int N, M;
    cin >> N >> M;
    int a[M];
    int b[M];
    for (int i=0; i<M; i++){
        cin >> a[i] >> b[i];
    }

    std::queue<std::vector<int>> que;
    std::vector<int> init{1};
    que.push(init);
    int counter = 0;
    while (!que.empty()){
        std::vector<int> now;
        now = que.front();
        que.pop();
        if (now.size()==N){
            counter++;
            continue;
        }
        for (int i=0; i<M; i++){
            if (a[i] == now.back()){
                if (!find(now, b[i])){
                    std::vector<int> newV = copyVector(now);
                    newV.push_back(b[i]);
                    que.push(newV);
                }
            }
            if (b[i] == now.back()){
                if (!find(now, a[i])){
                    std::vector<int> newV = copyVector(now);
                    newV.push_back(a[i]);
                    que.push(newV);
                }
            }
        }

    }
    cout << counter << endl;
}