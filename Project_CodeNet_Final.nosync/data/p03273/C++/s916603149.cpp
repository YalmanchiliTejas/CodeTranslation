#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H,W;cin>>H>>W;
  vector<string> a(H);
  vint x,y;
  repeat(i,H){
    cin>>a[i];
    repeat(j,W)if(a[i][j]=='#'){
      x.push_back(j);
      y.push_back(i);
    }
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  y.erase(unique(y.begin(),y.end()),y.end());
  repeat(i,y.size()){
    repeat(j,x.size()){
      cout<<a[y[i]][x[j]];
    }
    cout<<endl;
  }
  return 0;
}
