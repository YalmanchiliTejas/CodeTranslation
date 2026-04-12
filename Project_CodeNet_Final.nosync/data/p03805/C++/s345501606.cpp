#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < (n);i++)
ll INF = 1000000010; 
const ll MOD = 1000000007;


int main(){ 
    int n,m,ans = 0; cin >> n >> m;
    vector<int> v(n);
    rep(i,n) v[i] = i;
    vector<vector<int>> g(n,vector<int> (n));
    rep(i,m){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    do{
        bool ok = true;
        if(!v[0]){
            rep(i,n-1){
                if(!g[v[i]][v[i+1]]) ok = false;
            }
        }else continue;
        if(ok) ans++;
    }while(next_permutation(v.begin(),v.end()));

    cout << ans << endl;
} 