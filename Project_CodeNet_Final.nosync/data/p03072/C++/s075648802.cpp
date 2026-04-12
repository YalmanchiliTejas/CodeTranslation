#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
int n; 
  cin>>n;
  int h[n];
  rep(i, n){
    cin>>h[i];}
  
  int maxh=0;
  int cnt=0;
  rep(i, n){
    if(maxh<=h[i]){
      cnt++;
      maxh=h[i];
    }
  }
  
  cout<<cnt<<endl;
  
  
}