#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}
vector<vector<int>>v;
int n,m;
int ans = 0;
stack<int> s;
void dfs(int d,vector<bool> b,int next){
    b[next] = true;
    d++;
    if(d == n-1) {
        ans++;
    }else{
        for(int i = 0;i < v[next].size();i++){
            if(!b[v[next][i]]){
               dfs(d,b,v[next][i]);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int depth = 0;
    v.assign(n,vector<int>());
    vector<bool> b;b.assign(n,false);
    for(int i = 0;i < m;i++){
        int x,y; cin >> x >> y;x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0;i < v[0].size();i++){
        s.push(v[0][i]);
    }
    int next = 0;
    b[0] = true;
    for(int i = 0;i < v[0].size();i++){
        dfs(depth,b,v[0][i]);
    }
    cout << ans;
}

