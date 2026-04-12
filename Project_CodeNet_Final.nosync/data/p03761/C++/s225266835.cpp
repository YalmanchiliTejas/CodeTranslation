#include<bits/stdc++.h>
using namespace std;
main(){
  int n;
  cin>>n;
  vector<char> minimum(256, numeric_limits<char>::max());
  for(int i=1;i<=n;++i){
    string s;
    cin>>s;
    vector<char> n_chars(256);
    for(int i=0;i<s.size();++i)++n_chars[s[i]];
    for(int i=0;i<minimum.size();++i)
      minimum[i]=min(minimum[i],n_chars[i]);
  }
  for(int i=0; i<minimum.size();++i){
    char c=i;
    int n_chars=minimum[i];
    for(int i=0;i<n_chars;++i)cout<<c;
  }
  cout<<endl;
}
