#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n+1);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> num(n);
    iota(num.begin(), num.end(), 1);
    Graph perm;
    do{
        perm.push_back(num);
    }while(next_permutation(num.begin()+1, num.end()));

    int ans = 0, cnt;
    for(int i=0;i<perm.size();i++){
        cnt = 0;
        for(int j=0;j<n-1;j++){
            for(int k: G[perm[i][j]]){
                if(perm[i][j+1] == k) cnt++;
            }
        }
        if(cnt == n-1){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}