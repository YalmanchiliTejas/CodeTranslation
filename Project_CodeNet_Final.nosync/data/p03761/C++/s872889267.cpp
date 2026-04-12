#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans[26];
  rep(i,26) ans[i]=0;
  string s;
  cin >> s;
  rep(i,s.size()){
    int tmp=s[i]-'a';
    ans[tmp]++;
  }
  rep(i,n-1){
    string st;
    multiset<int> t;
    cin >> st;
    rep(j,st.size()){
      int ttt=st[j]-'a';
      t.insert(ttt);
    }
    rep(j,26){
      ans[j]=min((int)t.count(j),ans[j]);
    }
  }
  rep(i,26){
    rep(j,ans[i]){
      char c='a'+i;
      cout << c;
    }

  }
        
  
  return 0;
    

}
