#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,p=0,q=0;
  cin >> h >> w;
  vector<vector<char>> s(w,vector<char>(h));
  vector<char> u(h,'.');
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
    cin >> s.at(j).at(i);
    }
  }
  for (int i=0;i<w;i++) {
   if (s.at(i)!=u)
    q++;
  }
 vector<vector<char>> t(h,vector<char>(q));
 for (int i=0;i<w;i++) {
    if (s.at(i)!=u) {
     for (int j=0;j<h;j++)
       t.at(j).at(i-p)=s.at(i).at(j);
    }
    else
      p++;
  }
  vector<char> v(q,'.');
   for (int i=0;i<h;i++) {
     if (t.at(i)!=v) {
      for (int j=0;j<q;j++)
       cout << t.at(i).at(j);
      cout << endl;
     }
   }
}