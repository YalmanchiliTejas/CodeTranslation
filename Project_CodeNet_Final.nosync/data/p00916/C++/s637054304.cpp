#include<bits/stdc++.h>
using namespace std;
struct UnionFind
{
  vector< int > data;
  int parts;
  UnionFind(int size)
  {
    data.assign(size, -1);
    parts = size;
  }
  void Union(int x,int y)
  {
    x = Find(x), y = Find(y);
    if(x == y) return;
    --parts;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
  int Find(int x)
  {
    if(data[x] < 0) return(x);
    return(data[x] = Find(data[x]));
  }
  int size()
  {
    return(parts);
  }
};
 
int main()
{
  int N;
  int X1[50], Y1[50], X2[50], Y2[50];
 
  while(cin >> N, N) {
    vector< int > nums1, nums2;
    long long orr[300][300] = {{}};
 
    for(int i = 0; i < N; i++) {
      cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
      if(X1[i] > X2[i]) swap(X1[i], X2[i]);
      if(Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);
      nums1.push_back(X1[i]);
      nums1.push_back(X2[i]);
      nums2.push_back(Y1[i]);
      nums2.push_back(Y2[i]);
    }
    nums1.push_back(-1);
    nums2.push_back(-1);
    sort(nums1.begin(), nums1.end());
    nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
    sort(nums2.begin(), nums2.end());
    nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
    for(int i = 0; i < N; i++) {
      X1[i] = lower_bound(nums1.begin(), nums1.end(), X1[i]) - nums1.begin();
      X2[i] = lower_bound(nums1.begin(), nums1.end(), X2[i]) - nums1.begin();
      Y1[i] = lower_bound(nums2.begin(), nums2.end(), Y1[i]) - nums2.begin();
      Y2[i] = lower_bound(nums2.begin(), nums2.end(), Y2[i]) - nums2.begin();
      for(int j = X1[i]; j < X2[i]; j++) {
        for(int k = Y1[i]; k < Y2[i]; k++) {
          orr[j][k] |= 1LL << i;
        }
      }
    }
    UnionFind uftree(nums1.size() * nums2.size());
    for(int j = 0; j < nums1.size(); j++) {
      for(int k = 1; k < nums2.size(); k++) {
        if(orr[j][k - 1] == orr[j][k]) {
          uftree.Union(j * nums2.size() + k - 1, j * nums2.size() + k);
        }
      }
    }
    for(int j = 1; j < nums1.size(); j++) {
      for(int k = 0; k < nums2.size(); k++) {
        if(orr[j - 1][k] == orr[j][k]) {
          uftree.Union(j * nums2.size() + k - nums2.size(), j * nums2.size() + k);
        }
      }
    }
    cout << uftree.size() << endl;
  }
}