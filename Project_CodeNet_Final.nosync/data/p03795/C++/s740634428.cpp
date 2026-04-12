#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  int give,get;
  give=800*n;
  get=200*(n/15);
  cout<<give-get<<endl;
  return 0;
}
