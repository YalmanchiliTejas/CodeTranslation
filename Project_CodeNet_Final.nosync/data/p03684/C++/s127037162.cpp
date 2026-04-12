#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int i,j,n;
string str;

struct UnionFind {
  int *data;
  UnionFind(int size) {
      data = new int[size];
      for(int i = 0;i < size;i++)
          data[i] = -1;
  }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main(){
  cin >> n;
  vector<pair<int,int> > x,y;
  for(i = 0;i < n;i++){
    int xi,yi;
    cin >> xi >> yi;
    x.push_back(make_pair(xi,i));
    y.push_back(make_pair(yi,i));
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<pair<int,pair<int,int> > > d;
  for(int i = 0;i < n-1;i++){
    d.push_back(make_pair(abs(x[i].first-x[i+1].first),make_pair(x[i].second,x[i+1].second)));
    d.push_back(make_pair(abs(y[i].first-y[i+1].first),make_pair(y[i].second,y[i+1].second)));
  }
  sort(d.begin(),d.end());
  long long ans = 0;
  UnionFind uf(n);
  for(int i = 0;i < d.size();i++){
    if(uf.unionSet(d[i].second.first,d[i].second.second)){
      ans += d[i].first;
    }
  }
  cout << ans << endl;
}
