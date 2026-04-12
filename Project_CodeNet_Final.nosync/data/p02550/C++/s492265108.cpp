#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
//#define cocount cout << count << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define Cinint(n) int n;\
cin >> n;
#define Cinvecint(a, n) vector<int> a(n);\
for (int i = 0; i < (int)(n); i++) {\
  int num;\
  cin >> num;\
  a.at(i) = num;\
}
#define Cinstring(s) string s;\
cin >>s;


int main() {
  long long n, x, m;
  cin >> n >> x >> m;
  map<long, long> mapx;
  for(long long i = 0; i < m; i++){
    mapx[i] = 0;
  }
  long long sum = 0;
  long long a = x;
  mapx[x] = 1;
  vector<long long> retu(1);
  retu.at(0) = x;
  for(long long i = 0; i < n-1; i++){
    a = (a*a)%m;
    if (mapx[a] == 0) {
      mapx[a] = 1;
      retu.push_back(a);
    }
    else {
      retu.push_back(a);
      break;
    }
  }
  long long size = retu.size();
  long long numm;
  bool flag = false;
  for(long long i = 0; i < size-1; i++){
    if (retu.at(i) == retu.at(size-1)) {
      numm = i;
      flag = true;
      break;
    }
    else {
      sum += retu.at(i);
    }
  }
  if (!flag) {
    cout << sum+retu.at(size-1) << endl;
  }
  else {
    vector<long long> kurikae(1);
    kurikae.at(0) = retu.at(numm);
    for(long long i = numm+1; i<size-1; i++) {
      kurikae.push_back(retu.at(i));
    }
    long long kurikaesum = 0;
    long long ksize = kurikae.size();
    for(long long i = 0; i < ksize; i++){
      kurikaesum += kurikae.at(i);
    }
    sum += kurikaesum*((n-numm)/ksize);
    if ((n-numm)%ksize == 0) {
      cout << sum << endl;
    }
    else {
      for(long long i = 0; i < (n-numm)%ksize; i++){
        sum += kurikae.at(i);
      }
      cout << sum << endl;
    }
  }
  
}
    
  
    
      
      
      
      
    
    
