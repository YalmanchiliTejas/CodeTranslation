#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()

int vector_finder(vector<vector<int>> vec, vector<int> number){
  auto itr = find(all(vec),number);
  size_t index = distance(vec.begin(), itr);
  if (index != vec.size()){
    return 1;
  }
  else{
    return 0;
  }
}

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> paths;
  rep(i,M){
    int A,B;
    cin >> A >> B;
    vector<int> C = {A,B}, D = {B,A};
    paths.push_back(C);
    paths.push_back(D);
  }
  vector<int> points(N-1);
  rep(i,N-1){
    points.at(i) = i+2;
  }
  int ans = 0;
  sort(all(points));
  do {
    vector<int> v = points;
    v.push_back(1);
    int S = 1;
    rep(i,N-1){
      vector<int> path = {v.at(i), v.at(i+1)};
      if (!vector_finder(paths,path)){
        S = 0;
        break;
      }
    }
    if (S==1){
      ans++;
    }
  } while(next_permutation(all(points)));
  cout << ans << endl;
}