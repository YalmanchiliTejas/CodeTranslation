  #include <bits/stdc++.h>
  using namespace std;

  #define vi vector<int>
  #define all(v) v.begin(),v.end()
  #define ll long long int
  #define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define D1(x) {cerr<<" [" <<#x<<": "<<x<<"]";cout << endl;}
  #define D2(x) {cerr<<" [" <<#x<<": ";for(auto it:x)cerr<<it<< " ";cerr<<"] ";cout << endl;}

  const ll MOD=1e9+7;
  vector<vector<int>> edges(9,vector<int> (9));
  void solve(){
     int n,m;
     cin >> n >> m;
     vector<int> v(n);
     v[0]=1;
     for(int i=n-1;i>=1;i--){
       v[i]=i+1;
     }
     for(int i=0;i<m;i++){
       int a,b;
       cin >> a >> b;
       edges[a][b]=1;
       edges[b][a]=1;
     }
     int cnt=0;
     do{
       bool ok = true;
       for(int i=1;i<n;i++){
          if(!edges[v[i-1]][v[i]]){
              ok = false;
          }
       }
       if(ok)cnt++;
     }while(next_permutation(v.begin()+1,v.end()));

     cout << cnt;
  }



  int main(){
    IOS
       solve();
       cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
