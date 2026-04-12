#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
using i64 = long long;
using p = pair<int,int> ;
#define rep(i,s,e) for(int (i) = (s);i <= (e);(i)++)

int N;

vector<int> x;

vector<int> ans;

int main(){
  cin >> N;
  x.resize(N);
  ans.resize(N);
  rep(i,0,N - 1){
    cin >> x[i];
  }

  vector<p> vec;
  rep(i,0,N - 1) vec.push_back({x[i],i});

  sort(vec.begin(),vec.end());

  rep(i,0,N - 1){
    int index = vec[i].second;

    if(N / 2  <= i){
      ans[index] = vec[N / 2 - 1].first;
    }
    else{
      ans[index] = vec[N / 2].first;
    }
  }

  for(auto an : ans){
    cout << an << endl;
  }

}
