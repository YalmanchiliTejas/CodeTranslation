#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int graph[9][9]={0};
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a][b]++; graph[b][a]++;
    }
    vector<int> v;
    for(int i=0; i<N; ++i) v.push_back(i);
    
    int res=0;
    
    do{
        bool ok = true;
        for(int i=0; i<N-1; ++i){
            if(v[0]!=0){
                ok = false;
                break;
            }
            if(graph[v[i]][v[i+1]]==0) ok = false;
        }
        if(ok) res++;
    }while(next_permutation(v.begin(), v.end()) );
    cout << res << endl;
    return 0;
}