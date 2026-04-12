#include <bits/stdc++.h>
using namespace std;
int main(){

  vector <int> a(12);
  for(int i=0;i<12;i++) cin>>a[i];
  sort(a.begin(),a.end());

  int r=0;
  for(int i=0;i<12;i+=4) r+=(a[i]==a[i+1] && a[i]==a[i+2] && a[i]==a[i+3]);

  cout<<(r==3?"yes":"no")<<endl;

  return 0;

}

