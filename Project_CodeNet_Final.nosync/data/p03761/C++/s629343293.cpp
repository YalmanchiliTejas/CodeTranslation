#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int cnt[50][26];

int main() {
  int n;
  cin >> n;
  for (int i=0 ; i<n ; i++) {
    string str;
    cin >> str;
    for (int j=0 ; j<str.size() ; j++) {
      cnt[i][(int)(str[j]-'a')] += 1;
    }
  }

  for (int i=0 ; i<26 ; i++) {
    int min_cnt = 100;
    for (int j=0 ; j<n ; j++) {
      min_cnt = min(min_cnt, cnt[j][i]);
    }
    for (int j=0 ; j<min_cnt ; j++) {
      cout << (char)((int)'a' + i);
    }
  }
  cout << endl;
}
