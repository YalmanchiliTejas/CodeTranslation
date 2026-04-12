#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;


int main() {
   int n,m;
   cin >> n >> m;
   vector<int> a(n);
   rep(i,n) a.at(i)=i;
   set<pp> s;
   rep(i,m){
      int aa,b;
      cin >> aa >> b;
      s.insert(make_pair(aa,b));
      s.insert(make_pair(b,aa));
   }
   int ans=0;
   do {
      if (a.at(0)!=0) break;
      int u=0;
      rep(i,n-1){
         auto it=s.find(make_pair(a.at(i)+1,a.at(i+1)+1));
         if (it==s.end()) u=1;
      }
      if (u==0) ans++;
   } while(next_permutation(a.begin(),a.end()));
  cout << ans << endl;
  }