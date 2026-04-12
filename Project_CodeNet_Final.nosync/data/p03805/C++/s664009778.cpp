#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N, M;
    int count = 0;
    vector<vector<int>> connection;
    vector<int> arrange;

    cin >> N >> M;
    connection.resize(N, vector<int>());
    arrange.resize(N);
    for (int i = 0; i < N; i++){
        arrange[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        connection[a - 1].push_back(b - 1);
        connection[b - 1].push_back(a - 1);
    }

    do{
        if(arrange[0] == 0){
        bool ok = true;
        for (int i = 0; i < N - 1; i++){
            bool alive = false;
            for (int j = 0; j < connection[arrange[i]].size(); j++){
                if(connection[arrange[i]][j] == arrange[i + 1]){
                    alive = true;
                    break;
                }
            }
            if(!alive){
                ok = false;
                break;
            }
        }
        if(ok){
            count++;
        }
        }
    } while (next_permutation(arrange.begin(), arrange.end()));

    cout << count << endl;
}