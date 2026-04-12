#include <bits/stdc++.h>
using namespace std;

int counta = 0;
vector <int> v{};
vector<vector<int>> edge(30,vector<int>{});
vector<int> parmi{1};

void zentansaku(){
    if(!v.empty()){
        for(int i = 0;i < v.size();++i){
            int vi = v[i];
            int vback = v.back();
            v[i] = vback;
            v.pop_back();
            parmi.push_back(vi);
            zentansaku();
            parmi.pop_back();
            v[i] = vi;
            v.push_back(vback);
        }
    }
    else{
        bool can = 1; 
        for(int i = 0;i<parmi.size()-1;++i){
            bool ok = 0;
            for(int x:edge[parmi[i]]){
                if(x == parmi[i+1]){
                    ok =1;
                }
            }
            if(!ok){
                can = 0;
                break;
            }
        }
        if(can) counta++;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0;i<M;++i){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<N;++i){
        v.push_back(i+1);
    }
    zentansaku();
    cout << counta << endl;
    int l;
    cin >>l;
}