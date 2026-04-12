#include<bits/stdc++.h>
using namespace std;

//深さ優先探索を行い、条件を満たす物が何通りあるか調べる関数
int counter(vector<vector<int>> &board, vector<bool> &seen, int &count, int N, int before, int just){
    seen[just] = true;

    bool all_seen = true;

    for(int i=1; i<=N; i++){
        if(seen[i] == false) all_seen = false;
    }

    if(all_seen){
        count++;
        seen[just] = false;
        return 0;
    }

    seen[just] = false;

    for(int i : board[just]){
        if(i == before || seen[i]) continue;

        seen[just] = true;

        counter(board, seen, count, N, just, i);

        seen[just] = false; 
    }

    return 0;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N + 1);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;

        board[a].push_back(b);
        board[b].push_back(a);
    }

    vector<bool> seen(N+1, false);
    seen[0] = true;

    int count = 0;

    counter(board, seen, count, N, 0, 1);

    cout << count << endl;

}