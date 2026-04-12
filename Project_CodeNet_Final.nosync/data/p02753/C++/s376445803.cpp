#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
 string text; cin>>text;
  set<char> ans;
  for(int i=0;text[i];i++) ans.insert(text[i]);
  if(ans.size()==2) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
