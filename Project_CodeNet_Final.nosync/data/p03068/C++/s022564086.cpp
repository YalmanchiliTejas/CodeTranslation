#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  string s;
  cin>>n>>s>>k;
  for(int i=0;i<n;i++) {
  	if(s[i]!=s[k-1]) s[i]='*';
  }
	cout<<s;
  return 0;
}