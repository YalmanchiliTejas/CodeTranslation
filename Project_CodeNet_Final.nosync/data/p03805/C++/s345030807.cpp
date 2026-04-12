#include <bits/stdc++.h>


using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int a[2 * M], b[2 * M];
    for(int i = 0; i < M; ++i){
        cin >> a[i] >> b[i];
        a[i + M] = b[i];
        b[i + M] = a[i];
    }
    
    queue<vector<int>> que;
    que.push({1});
    int cnt = 0;
    
    while(que.size() > 0){
        vector<int> v = que.front();
        que.pop();
        
        if(v.size() == N){
            ++cnt; continue;
        }
        
        for(int i = 0; i < 2 * M; ++i){
            if(a[i] == v[v.size() - 1]){
                bool flag = 1;
                for(int j = 0; j < v.size(); ++j){
                    if(b[i] == v[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    vector<int> temp = v;
                    temp.push_back(b[i]);
                    que.push(temp);
                }
            }
        }
    }
    cout << cnt << endl;
}