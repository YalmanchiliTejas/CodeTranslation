#include <bits/stdc++.h>
using namespace std;void solve();int main(){ios::sync_with_stdio(0);cin.tie(0);solve();};typedef long long ll;
template<typename Type>void print_collection(Type coll){cout<<"{ ";for(auto e:coll)cout<<e<<' ';cout<<"}\n";}
void solve() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  for (int i=0; i < n; ++i)
    if (s[i] != s[k-1])
      s[i] = '*';
  cout << s << '\n';
}