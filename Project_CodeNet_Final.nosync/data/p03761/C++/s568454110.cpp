#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  vector<int> a(26,50);
  vector<int> b(26,0);
  for(int i=0; i<n; i++) {
    cin >> s;
    for(int j=0; j<s.size(); j++) {
      b[s[j]-'a']++;
    }
    for(int j=0; j<26; j++) {
      a[j]=min(a[j],b[j]);
      b[j]=0;
    }
  }
  char c;
  for(int i=0; i<26; i++) {
    c='a'+i;
    for(int j=0; j<a[i]; j++) {
      cout << c;
    }
  }
  cout << endl;
}