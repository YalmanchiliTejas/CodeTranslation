#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define pii pair<int,int>
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  int n,m,ans=0; cin>>n>>m;
  vector<vector<bool>> v(n,vector<bool>(n));
  rep(i,0,m){
    int a,b; cin>>a>>b;
    v[a-1][b-1]=true; v[b-1][a-1]=true;
  }
  vector<int> tem={};
  rep(i,0,n) pb(tem,i);
  do{
    bool f=true;
    rep(i,0,tem.size()-1){
      if(!v[tem[i]][tem[i+1]]){
      	f=false;
      	break;
      }
    }
    if(f) ans++;
  }while(next_permutation(tem.begin()+1,tem.end()));
  co(ans);
  
  return 0;
}