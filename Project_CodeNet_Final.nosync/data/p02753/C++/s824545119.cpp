#include<bits/stdc++.h>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
  string s;
  cin >> s;
  if((s.at(0) == s.at(1)) && (s.at(1) == s.at(2))) cout << "No" << endl;
  else cout << "Yes" << endl;
}