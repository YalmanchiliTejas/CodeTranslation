#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  string ans;
  if(n==3 || n==5 || n==7) ans = "YES";
  else ans = "NO";
  cout << ans << endl;
  return 0;
}
