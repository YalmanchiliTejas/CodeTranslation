#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;


bool bless(const pair<int, int> &p, const pair<int, int> &q) {
  return (p.first != q.first) ? p.first > q.first : p.second < q.second;
}

int main() {
  int n,f=0;
  while(cin>>n, n) {
    if(f) cout<<endl;
    vector< pair<int, int> > v;
    vector<string> w;
    string s;
    int a,b,c;
    for(int i=0; i<n; ++i) {
      cin>>s>>a>>b>>c;
      v.push_back( pair<int,int>(a*3+c,i) );
      w.push_back(s);
    }

    stable_sort(v.begin(), v.end(), bless);

    for(int i=0; i<n; ++i)
      cout<<w[v[i].second]<<","<<v[i].first<<endl;
    f=1;
  }
}