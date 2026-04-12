#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
  int *data;
  UnionFind(int *_data, int size) : data(_data) {
    for(int i = 0; i < size; i++) data[i] = -1;
  }
  bool unionSet(int x, int y) {
    x = find(x); y = find(y);
    if (x != y) {
      if (data[y] < data[x]) std::swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }
  int size(int x) {
    return -data[find(x)];
  }
};

int main(int argc, char *argv[])
{
  for(;;) {
    int n;
    cin >> n;
    if(n == 0) break;
    vector<vector<int>> ps;
    vector<int> xss;
    vector<int> yss;
    {
      vector<int> xs;
      vector<int> ys;
      for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ps.push_back({a,d,c,b});
        xs.push_back(a);
        ys.push_back(b);
        xs.push_back(c);
        ys.push_back(d);
      }
      xs.push_back(-1);
      xs.push_back(1000001);
      ys.push_back(-1);
      ys.push_back(1000001);
      sort(xs.begin(), xs.end());
      sort(ys.begin(), ys.end());
      unique_copy(xs.begin(), xs.end(), back_inserter(xss));
      unique_copy(ys.begin(), ys.end(), back_inserter(yss));
    }
    int nx = xss.size()-1;
    int ny = yss.size()-1;
    vector<vector<long long>> rs(ny, vector<long long>(nx, 0L));
    // fill the rectangles!
    for(int i = n - 1; i >= 0; i--) {
      for(int j = 0; j < ny; j++) {
        const int y = yss[j];
        if(ps[i][1] <= y && y < ps[i][3]) {
          for(int k = 0; k < nx; k++) {
            const int x = xss[k];
            if(ps[i][0] <= x && x < ps[i][2]) {
              rs[j][k] |= (1L << i);
            }
          }
        }
      }
    }
    // let's count the number of regions!
    vector<int> ufdata(ny * nx);
    UnionFind uf(&(ufdata[0]), ny * nx);
    for(int j = 0; j < ny; j++) {
      for(int k = 0; k < nx; k++) {
        if(j > 0 && rs[j][k] == rs[j-1][k]) uf.unionSet(j * nx + k, (j-1) * nx + k);
        if(k > 0 && rs[j][k] == rs[j][k-1]) uf.unionSet(j * nx + k, j * nx + (k-1));
      }
    }
    int cnt = 0;
    for(int j = 0; j < ny; j++) {
      for(int k = 0; k < nx; k++) {
        int id = j * nx + k;
        if(uf.find(id) == id) cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

  

