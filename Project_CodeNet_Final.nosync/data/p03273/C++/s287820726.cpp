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


int main() {
    int n,m; cin >> n >> m;
    vector<vector<char>> v;v.assign(n,vector<char>());
    for(int i = 0;i < n;i++){
        string s; cin >> s;
        if(s.find('#') != string::npos){
            for(int j = 0;j < m;j++){
                v[i].push_back(s[j]);
            }
        }else{
            i--;
            n--;
        }
    }
    
    for(int i = v[0].size()-1;i >= 0;i--){
        int cnt = 0;
        if(v[0][i] == '.'){
            for(int j = 0;j < n;j++){
                if(v[j][i]=='.'){
                    cnt++;
                }
            }
        }
        if(n == cnt){
            for(int j = 0;j < n;j++){
                v[j].erase(v[j].begin()+i);
            }
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < v[i].size();j++){
            cout << v[i][j];
        }
        cout << endl;
    }
}


