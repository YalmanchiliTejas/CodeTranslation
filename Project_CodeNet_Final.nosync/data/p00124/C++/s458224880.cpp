#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  bool did=false;
  while(cin >> n){
    if(n==0){
      return 0;
    }
    if(did){
      cout << endl;
    }
    string s[n];
    long long win[n],draw[n],lose[n];
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
      cin >> s[i] >> win[i] >> lose[i] >> draw[i];
      p[i]=make_pair(win[i]*3+draw[i],i);
    }
    sort(p,p+n);
    reverse(p,p+n);
    for(int i=0;i<n;i++){
      bool f=true;
      for(int j=i;j<n;j++){
        if(p[j].first<p[i].first){
          for(int k=j-1;k>=i;k--){
            cout << s[p[k].second] << "," << p[k].first << endl;
          }
          f=false;
          i=j-1;
          break;
        }
      }
      if(f){
        for(int j=n-1;j>=i;j--){
          cout << s[p[j].second] << "," << p[j].first << endl;
        }
        break;
      }
    }
    did=true;
  }
  return 0;
}
