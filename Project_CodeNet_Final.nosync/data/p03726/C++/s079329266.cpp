#include<iostream>
#include<vector>
using namespace std;
int n, i, x, y, j, ok;
int c[100005];
vector<int> v[100005];
void dfs(int nod, int t){
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(vecin != t){
            dfs(vecin, nod);
            if(c[vecin] == 0){
                if(c[nod] == 1){
                    ok = 0;
                }
                c[nod] = 1;
            }
        }
    }
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ok = 1;
    dfs(1, 0);
    if(c[1] == 0){
        ok = 0;
    }
    if(ok == 0){
        cout<<"First";
    }
    else{
        cout<<"Second";
    }
}
