#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
using P = pair<int, int>;
const ll inf =1e9;

struct edge{
    int to;
    int cost;
};
using graph = vector<vector<edge>>;

int main(){
    int n, m; cin >> n >> m;
    if(n == m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}