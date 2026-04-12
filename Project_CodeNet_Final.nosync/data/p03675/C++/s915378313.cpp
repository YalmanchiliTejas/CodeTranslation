#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <time.h>
using namespace std;
typedef long long ll;
const int maxn = 200005;

int n,a[maxn],b[maxn];

int main() {
#ifdef suiyuan2009
  freopen("in.cpp","r",stdin);
#endif
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  int l = 0, r = n-1;
  for(int i=n-1;i>=0;i--){
    if((n-i)&1)b[l++]=a[i];
    else b[r--]=a[i];
  }
  for(int i=0;i<n-1;i++)cout<<b[i]<<" ";
  cout<<b[n-1]<<endl;
  return 0;
}

