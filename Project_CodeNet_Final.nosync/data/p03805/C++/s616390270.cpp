//
// Created by 田代真生 on 2019-10-09.
//

#include <bits/stdc++.h>
using namespace std;

long n, m;
long a, b;

bool search(vector<long> ls, long n, vector<vector<long>> _map){
    for(long i=0; i< n-1; i++){
        if(_map[ls[i]][ls[i+1]] == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    bool res;
    long cnt = 0;
    vector<vector<long>> _map(n, vector<long>(n, 0));
    vector<long> list(n);
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        _map[a][b] = 1;
        _map[b][a] = 1;
    }
    for(int i=0; i<n; i++){
        list[i] = i;
    }
    do{
        res = search(list, n, _map);
        if(res){
            cnt++;
        }
    } while (
        next_permutation(list.begin()+1, list.end())
    );
    cout << cnt << endl;
}