#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
using namespace std;
#define MAX 1000000007
typedef long long ll;



int main(){
  int n,a[210000],ans[210000];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<(n+1)/2;i++){
    ans[i]=a[n-1-i*2];
    if(n-2-i*2<0) break;
    ans[n-1-i]=a[n-2-i*2];
  }
  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  
}
