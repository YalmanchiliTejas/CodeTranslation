#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,b,c;
  cin>>a>>b>>c;
  a-=c;
  b+=c;
  c=a/b;
  cout<<c;
}
