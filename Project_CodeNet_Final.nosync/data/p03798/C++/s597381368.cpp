#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll query(int left, int now, char c) {
  if(now == 0) {
    return (c == 'o') ? left : (left+1) % 2;
  }

  return (c == 'x') ? left : (left+1) % 2;
}

int arr[100001];
const int dir[4][2] = {{0,0},{0,1},{1,0},{1,1}};

string solve(ll n, string s) {

  for(int x=0; x<4;x++) {
    for(int i=0; i< n; i++) {
      arr[i] = -1;
    }

    arr[0] = dir[x][0];
    arr[1] = dir[x][1];

    for(int i = 2; i < n; ++i) {
      arr[i] = query(arr[i-2], arr[i-1], s[i-1]);
    }

    // check
    if(arr[0] == query(arr[n-2], arr[n-1], s[n-1]) &&
       arr[1] == query(arr[n-1], arr[0],   s[0])) {
      string ret="";
      for(int i=0;i<n;++i) {
        ret += (arr[i]==0)? "S" : "W";
      }
      return ret;
    }
  }
  return "-1";
}
int main() {
  ll n;
  string s;
  cin >> n >> s;
  cout<< solve(n, s)<<endl;
}
