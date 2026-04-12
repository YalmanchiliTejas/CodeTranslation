#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> graph[10];
bool reached[10];
void search(int position);
int route = 0;

int main(){
    cin >> N >> M;
    for (int i = 1; i <= M; i++){
        int x, y;
        //無向グラフ
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= N; i++){
        reached[i] = false;
    }
    reached[1] = true;
    search(1);
    cout << route << endl;
}
void search(int position){
    bool all_reached = true;
    for (int i = 1; i <= N; i++){
        if (reached[i] == false){
            all_reached = false;
        }
    }
    if (all_reached){
        route++;
        return;
    }

    for (int i = 0; i < graph[position].size(); i++){
        int nextposition = graph[position][i];
        if (reached[nextposition] == false){
            reached[nextposition] = true;
            search(nextposition);
            reached[nextposition] = false;
        }
    }
}