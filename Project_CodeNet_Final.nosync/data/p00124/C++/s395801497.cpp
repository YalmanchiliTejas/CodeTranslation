#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,pair<int,string> > P;
int main(void){
  int n,w,l,d,f = 0;
  string t;
  while(cin >> n,n){
    if(f) cout << "\n";
    f = 1;
    vector<P> v;
    for(int i = 0;i < n; i++){
      cin >> t >> w >> l >> d;
      P p;
      p.first = w * 3 + d;
      p.second.first = n - i;
      p.second.second = t;
      v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i = n - 1;i >= 0; i--) cout << v[i].second.second << "," << v[i].first << endl;
  }
}
