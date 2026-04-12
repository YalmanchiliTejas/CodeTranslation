#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long INF = 1e9;

int main(){
  long long n,x,m;
  const long long max_x = 1e5;
  cin >> n >> x >> m;

  long long a = x;
  long long num[max_x + 1] = {};
  vector<long long> ans;
  ans.push_back(a);
  long long e = 0;
  num[x] = 1;
  do{
    a = a * a % m;
    num[a] = 1;
    ans.push_back(a);
    e = a*a%m;
  }while(num[a*a%m] == 0);

  // for(long long i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  
  a = x;
  long long pos;
  for(long long i = 0; i < ans.size(); i++){
    if(ans[i] == e) pos = i;
  }

  long long cnt = ans.size() - pos;
  // cout << pos << endl;
  // cout << cnt << endl;
  // cout << ans.size() << endl;

  long long sum = 0;
  long long part = 0;
  for(long long i = pos; i < ans.size(); i++){
    part += ans[i];
  }

  for(long long i = 0; i < pos; i++){
    sum += ans[i];
  }
  long long n2 = n - pos;
  long long c = n2 / cnt;
  sum += part * c;
  for(long long i = pos; i < pos + n2 % cnt; i++){
    sum += ans[i];
  }
  cout << sum << endl;
  
  return 0;
}