#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++)cin >> a[i];

  sort(a.begin(),a.end());

  vector<ll> b;
  vector<ll> c;

  ll lea1;
  ll lea2;
  for(int i = 0;i < n;i++){
    if(n - b.size() == 1){
      lea1 = i % 2 == 0 ? a[n-1-i/2] : a[i/2];
      break;
    }
    if(i % 2 == 0)b.push_back(a[n-1-i/2]);
    else b.push_back(a[i/2]);
  }

  for(int i = 0;i < n;i++){
    if(n - c.size() == 1){
      lea2 = i % 2 == 0 ? a[i/2] : a[n-1-i/2];
      break;
    }
    if(i % 2 == 0)c.push_back(a[i/2]);
    else c.push_back(a[n-1-i/2]);
  }
  
  ll ans1 = max(abs(lea1-b[0]),abs(lea1-b[n-2]));
  for(int i = 0;i < b.size()-1;i++){
    ans1 += abs(b[i]-b[i+1]);
  }

  ll ans2 = max(abs(lea2-c[0]),abs(lea2-c[n-2]));
  for(int i = 0;i < c.size()-1;i++){
    ans2 += abs(c[i]-c[i+1]);
  }

  cout << max(ans1,ans2) << endl;
}