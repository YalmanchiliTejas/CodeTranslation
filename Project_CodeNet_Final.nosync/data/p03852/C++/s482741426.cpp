#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  char c; cin >> c;
  if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u'){
    cout << "vowel\n";
  } else {
    cout << "consonant\n";
  }
  return 0;
}