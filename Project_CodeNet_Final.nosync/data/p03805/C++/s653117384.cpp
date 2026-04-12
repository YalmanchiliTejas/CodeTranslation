#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <cstring>
#include <stack>
#include <iomanip>
#include <climits>
#include <numeric>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define show(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
int G[10][10];
int main(){
    cin >> n >> m;
    int a,b;
    rep(i,m){
        cin >> a >> b;
        G[a][b]=1;
        G[b][a]=1;
        
    }
    vector<int>c(n-1);
    rep(i,n-1){
        c[i] = i+2;
    }
    sort(c.begin(),c.end());
    int ans = 0;
    do{
        bool f = true;
        if(G[1][c[0]]==0)continue;
        rep(i,n-2){
            if(G[c[i]][c[i+1]]==0)f=false;;
        }
        if(f)ans++;
        
    }while(next_permutation(c.begin(),c.end()));
    cout << ans << endl;
}