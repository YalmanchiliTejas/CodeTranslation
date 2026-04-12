    #include <bits/stdc++.h>
    using namespace std;
    
    vector<vector<long>> adj;
    long n, m;
    long ans = 0;
    
    void dfs(long bit , long next){
        bit = bit | (1 << next);
        if(__builtin_popcountl(bit) >= n){
            ans += 1;
            return;
        }
        for(int i = 0 ; i < adj[next].size() ; i++){
            if( !((bit >> adj[next][i]) & 1) )
                dfs(bit , adj[next][i]);    
        }
        
        return;
    }

    int main(){
      
      long a , b;
      cin >> n >> m;
      //vector<vector<long>> adj;
      for(int i = 0 ; i < n ; i++ ){
          vector<long> a;
          adj.push_back(a);
      }
      for(int i = 0 ; i < m ; i++ ){
          cin >> a >> b;
          adj[a - 1].push_back(b -1);
          adj[b - 1].push_back(a -1);
      }
      dfs(0 , 0);
      
      cout << ans << endl;
      
      return 0;
    }