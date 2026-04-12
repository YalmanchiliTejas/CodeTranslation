#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> pl;
const int INF=100000001;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  multiset<int> s;
  rep(i,n){
    cin>>a[i];
  }
  int ans=0;
  rep(i,n){
    auto it=s.upper_bound(-a[i]);
    if(it==s.end()){
      ans++;
    }else{
      s.erase(it);
    }
    s.insert(-a[i]);
  }
  cout<<ans<<endl;
  return 0;
}
