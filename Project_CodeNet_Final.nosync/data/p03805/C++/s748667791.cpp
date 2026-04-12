#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n, m;
    cin >> n >> m;
    vector<int> num_list;
    vector<vector<int>> g(n, vector<int> (n, 0));
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    
    for (int i=0; i<n; i++){
        num_list.push_back(i);
    }
    
    int ans = 0;
    do{
        bool flag = true;
        if(num_list[0] != 0) flag = false;
        for (int i=0; i<n-1; i++){
            if (g[num_list[i]][num_list[i+1]] == 0) flag = false;
        }
        if(flag) ans++;
    }while(next_permutation(num_list.begin(), num_list.end()));
    
    cout << ans << endl;
}
