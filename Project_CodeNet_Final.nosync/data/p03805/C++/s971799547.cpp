#include<iostream>
#include<queue>
#include<utility>
#include<tuple>
#include<algorithm>
#include<set>
using namespace std;

typedef vector< set<int> > sets;

int main(){
    int N, M;
    int a, b, cnt = 0;
    cin >> N >> M;
    sets E(N+1);
    vector<int> vi;
    bool flag = true;
    for(int i = 1; i <= M; i++){
        cin >> a >> b;
        E[a].insert(b);
        E[b].insert(a);
    }
    for(int i = 2; i <= N; i++){
        vi.push_back(i);
    }
    // cout << vi.size()<< endl;;
    do{
        flag = true;
        if(E[1].count(vi[0]) == 0)continue;
        for(int i = 0; i < N-2; i++){
            if(E[vi[i]].count(vi[i+1]))continue;
            else flag = false;
        }
        // cout << "flag:" <<flag << endl;
        // " vi:" << vi << endl;
        if(flag)cnt++;
    }while(next_permutation(vi.begin(), vi.end()));
    
    cout << cnt << endl;
}