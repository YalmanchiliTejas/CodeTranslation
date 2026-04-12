#include<bits/stdc++.h>


using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string a, b;
  int n;
  cin >> n;
  int c[26];
  for(int i = 0; i < 26; i++){
    c[i] = 1 << 25;
  }
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    for(int j = 0; j < 26; j++){
      c[j] = min<int>(c[j], upper_bound(str.begin(), str.end(), j + 'a') - lower_bound(str.begin(), str.end(), j + 'a'));
    }
  }
  for(int i = 0; i < 26; i++){
    while(c[i]--)
      cout << char(i + 'a');
  }
  cout << "\n";
}