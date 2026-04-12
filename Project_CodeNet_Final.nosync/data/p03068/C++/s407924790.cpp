#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define ifr(i,n) for(int i=n-1;i>=0;i--)


int main() {
  int n,k;
  string s;
  cin >> n >> s >> k;
  fr(i,n){
   if(s.substr(k-1, 1)!=s.substr(i, 1))
  s.replace(i, 1, "*");
  }
  cout << s << endl;
}
