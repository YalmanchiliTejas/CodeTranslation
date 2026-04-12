#include<bits/stdc++.h>
using namespace std;

int main(){

    //入力
    int n, m, k; cin >> n >> m >> k;
    map<int, int> M;
    for(int i = 0; i < m; i++){
        int input; cin >> input;
        M[input] = i;
    }

    vector<vector<int> > G(m + 1, vector<int> (k, -1));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            int input; cin >> input;
            int a, b;
            if(M.count(i)) a = M[i];
            else a = m;

            if(M.count(input)) b = M[input];
            else b = m;

            G[a][j] = b;
        }
    }
    G[m][m] = -1;

    /*for(int i = 0; i <= m; i++){
        for(int j = 0; j < k; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    priority_queue<pair<int, int> > pb;
    pb.push({0, 0});
    vector<bool> used((1<<m), false);
    used[0] = true;
    while(1){

        int bit = pb.top().second;
        int cost = -pb.top().first;
        //cout << bitset<8>(bit) << " " << pb.size() << endl;
        //int q; cin >> q; 
        if(bit == (1<< m) - 1){
            cout << cost << endl;
            return 0;
        }

        pb.pop();

        for(int i = 0; i < k; i++){
            int nextbit = (1<<m) - 1;
            for(int j = 0; j < m; j++){
                if(~bit & (1<<j)){
                    nextbit &= ~(1<<G[j][i]);
                }
            }

            nextbit &= ~(1<<m);

            if(!used[nextbit]){
                pb.push({-(cost + 1), nextbit});
                used[nextbit] = true;
            }
        }
    }

    return 0;
}
