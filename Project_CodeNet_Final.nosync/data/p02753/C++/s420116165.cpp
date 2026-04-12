#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
const ll N = 2e5+10;



void solve(){
            
      string s;cin>>s;
      set<char>st;
      for(auto &k:s){
          st.insert(k);
      }
      st.size()==1?cout<<"No":cout<<"Yes";
      
  
           
}


int main(){
    
        #ifdef debug
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout); 
            
        #endif
            ios_base::sync_with_stdio(0);
            cin.tie(0);cout.tie(0);
            
            
                solve();
            
            
            
        return 0;
}
