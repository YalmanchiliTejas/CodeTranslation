#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int,int>;

void keiro(const vector<vector<int>> &edge, int v, vector<int> &trace);
int ans = 0;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(n,0));
    vector<int> trace(n, 0);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        edge.at(a - 1).at(b - 1) = 1;
        edge.at(b - 1).at(a - 1) = 1;
    }
    keiro(edge, 0, trace);
    cout << ans << endl;
}

void keiro(const vector<vector<int>> &edge, int v, vector<int> &trace){
    trace.at(v) = 1;
    int sum = 0;
    for(int x : trace){
        sum += x;
    }
    if(sum == edge.at(v).size()){
        ans++;
    }
    else{
        for(int i = 0; i < edge.at(v).size(); i++){
            if(edge.at(v).at(i) == 1 && trace.at(i) == 0){
                keiro(edge, i, trace);
            }
        }
    }
    trace.at(v) = 0;
}