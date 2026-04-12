#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int M, N;

bool is_ok(vector<int>& mem, vector<vector<int>>& rel){
    for (int i = 0; i < N - 2; i++){
        //i番目の要素からi + 1番目の要素へ行けるか判定
        if (count(rel.at(mem.at(i)).begin(), rel.at(mem.at(i)).end(), mem.at(i + 1)) <= 0){
            return false;
        }
    }
    if (count(rel.at(0).begin(), rel.at(0).end(), mem.at(0)) <= 0){
            return false;
    }
    return true;
}
int main(){
    int temp1, temp2;
    cin >> N >> M;
    vector<vector<int>> rel(N, vector<int>(0));
    for (int i = 0; i < M; i++){
        cin >> temp1 >> temp2;
        rel.at(temp1 - 1).push_back(temp2 - 1);
        rel.at(temp2 - 1).push_back(temp1 - 1);
    }
    vector<int> mem(N - 1);
    for (int i = 1; i < N; i++){
        //mem = {1, 2, 3, ... , N - 1(idx N - 2)}
        mem.at(i - 1) = i;
    }

    int cnt = 0;
    do{
        if (is_ok(mem, rel)){
            cnt++;
        }
    }while(next_permutation(mem.begin(), mem.end()));

    cout << cnt << endl;
}