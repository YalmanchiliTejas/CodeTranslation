#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n,m;
  cin >> n>>m;
  int ans=0;
  vector<int>a(m),b(m);
  rep(i,m){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<vector<bool>>x(n,vector<bool>(n));
  rep(i,m){
    x.at(a.at(i)).at(b.at(i))=true;
    x.at(b.at(i)).at(a.at(i))=true;    
  }
  vector<int>r;
  rep2(i,1,n){
    r.push_back(i);
  }
  sort(r.begin(), r.end());
  do {
    bool ch=true;
    if(!x.at(0).at(r.at(0))){
      ch=false;
    }
    rep(i,r.size()-1){
      if(!x.at(r.at(i)).at(r.at(i+1))){
        ch=false;
      }
    }
    if(ch){
      ans++;
    }
  } while (next_permutation(r.begin(), r.end()));
 
  cout<<ans<<endl;
}