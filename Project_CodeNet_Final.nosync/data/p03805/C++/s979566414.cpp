#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(8,vector<int>(8));
// vector<bool> visited(8,false);
int ans;
int n, m;


int main(void){
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a][b]++;
        G[b][a]++;
    }
    
    ans = 0;
   
   vector<int> ord(n);
   for (int i = 0; i < n; i++) ord[i] = i;
   
   do{
       
       if (ord[0] != 0) break;
       
       bool check = true;
       
       for (int i = 0; i +1 < n; i++){
           int from = ord[i];
           int to = ord[i+1];
           
           if (G[from][to]) continue;
           else check = false;
       }
       
       if (check) ans++;
       
   } while (next_permutation(ord.begin(),ord.end()));
    
    cout << ans << endl;
    return 0;
    
}
