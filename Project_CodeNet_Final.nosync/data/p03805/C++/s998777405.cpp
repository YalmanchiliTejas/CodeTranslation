#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} //配列vにn個の要素を入力する
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define push_back pb

const int mod = 1000000007;

int n, m;
vi a, b;
vb v; //訪問済みかどうかのチェック

int dfs(int i, int k){
    // i : 探索数, k : 今の頂点
    if(v.at(k)){return 0;}
    if(i == n){return 1;}

    v.at(k) = true;

    int cnt = 0;

    rep(j, 0, m){
        if(a.at(j)==k){cnt += dfs(i + 1, b.at(j));}
        if(b.at(j)==k){cnt += dfs(i + 1, a.at(j));}
    }

    v.at(k) = false;

    return cnt;
}

int main(){
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    v.assign(n, false);
    rep(i, 0, m){cin >> a.at(i) >> b.at(i);a.at(i)--;b.at(i)--;}
    cout << dfs(1, 0);
}
    