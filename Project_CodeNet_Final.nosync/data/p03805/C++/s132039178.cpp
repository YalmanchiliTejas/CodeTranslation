#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m;
    int a, b;
    set<int> connect[8];
    vector<int> v;
    for(i = 0; i < m; i++){
        cin >> a >> b;
        connect[a-1].insert(b-1);
        connect[b-1].insert(a-1);
    }
    for(i = 0; i < n; i++){
        v.push_back(i);
    }

    int c = 0;
    do{
        if(v[0] != 0) continue;
        for(i = 0; i < n-1; i++){
            if(connect[v[i]].count(v[i+1]) != 1) break;
        }
        if(i == n-1) c++;
    }while(next_permutation(v.begin(), v.end()));
    cout << c << endl;

}