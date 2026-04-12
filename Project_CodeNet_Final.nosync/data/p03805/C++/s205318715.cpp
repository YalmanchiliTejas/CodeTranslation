#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int per[8];
vector<int> g[8];
int n;
int m;

bool ispath(int x){
    if(x == 0){
        if(per[x] != 0){
            return false;
        }
    }
    // cout << x << endl;
    if (x == n - 1){
        return true;
    }
    for (int i = 0; i < g[per[x]].size(); i++){
        if (g[per[x]][i] == per[x+1]){
            return ispath(x + 1);
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    int a, b;
    rep(i, m){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, n) per[i] = i;
    int ans = 0;
    do{

        // rep(i, n) cout << per[i];
        // cout << endl;
        if (ispath(0)){
            ans++;
        }
    }while(next_permutation(per, per + n));
    cout << ans << endl;
    
}