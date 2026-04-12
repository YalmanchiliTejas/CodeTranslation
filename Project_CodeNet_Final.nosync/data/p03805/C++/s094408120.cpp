#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
int main(){
   int n,m;
   cin >> n >> m;
   vector<vector<int>> edge(n);
   vector<int> p(n);
   vector<bool> visited(n,false);
   rep(i,n) p[i]=i+1; 
   rep(i,m){
      int x,y;
      cin >> x >> y;
      x--;y--;
      edge[x].push_back(y);
      edge[y].push_back(x);
   }
   bool can = true;
   ll ans=0;
   do{
      for (int i=0;i < n-1;i++){
         for (auto q:edge[p[i]-1]){
            if (q != p[i+1]-1) {
               can =false;
            }
            else {
               can=true;
               break;
            }
         }
         if (!can) break; 
      }
      if (can) ans++;
      //rep(i,n){
      //   cout << p[i] << " ";
      //}
      //if (can) printf(" o\n");
      //else printf("  x\n");

   }while(next_permutation(p.begin()+1,p.end()));

   cout << ans << endl;
   return 0;
}

