#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    
    int ans = 0;
    vector<int> way;
    for(int i = 1; i < n; i++) way.push_back(i);
    do{
        bool path = true;
        rep(i, n - 1){
            bool reach = false;
            if(i == 0){
                for(int t : to[i]){
                    if(t == way[i])reach = true;
                }
            }else{
                for(int t : to[way[i - 1]]){
                    if(t == way[i])reach = true;
                }
            }
            if(!reach)path = false;
        }
        if(path)ans++;
    }while(next_permutation(way.begin(), way.end()));
    cout << ans << endl;
}