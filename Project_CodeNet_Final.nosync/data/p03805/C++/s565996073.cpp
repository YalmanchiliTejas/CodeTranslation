#include <bits/stdc++.h>
using namespace std;
int N,M;
int a,b;
int p[9][9] = {};
int ans;
vector<int> vec;
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        p[a][b] = p[b][a] = 1;
    }
    
    for(int i = 1; i <= N; i++){
        vec.push_back(i);
    }
    
    int ctr = 0;
    
    do{
        int ans = 1;
        for(int i = 0; i < N-1; i++){
            ans *= p[vec.at(i)][vec.at(i+1)];
        }
        if(ans){
            ctr++;
        }
    }while(next_permutation(vec.begin()+1,vec.end()));
    
    cout << ctr << endl;
    
}