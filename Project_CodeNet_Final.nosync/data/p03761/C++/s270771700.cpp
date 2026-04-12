#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
ll mod=1000000007;

int main() {
  int n;cin>>n;
  vector<string> v;
  for(int i=0;i<n;++i){
    string s;cin>>s;
    vector<string> vt;
    if(i==0){
      for(int j=0;j<s.size();++j) v.push_back(s.substr(j,1));
    } else {
      for(int k=0;k<s.size();++k) vt.push_back(s.substr(k,1));
      sort(vt.begin(),vt.end());
      vector<string> vt2 = v;
      v.resize(0);
      set_intersection(vt.begin(), vt.end(),vt2.begin(), vt2.end(),
                       inserter(v, v.end()));
    }
    sort(v.begin(),v.end());
  }
  if(v.size()>0){
    for(int l=0;l<v.size();++l)
    cout << v[l];
  }
  cout << endl;
  return 0;
}
