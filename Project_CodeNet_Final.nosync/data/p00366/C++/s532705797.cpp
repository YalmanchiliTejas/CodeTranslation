#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
int ret[1000000];

int main(){
  int n;
  cin>>n;
  int a[1000000],num=0;
  lp(i,n){
    cin>>a[i];
    num=max(a[i],num);
  }
  int ans=0,memo,count;
  lp(i,n){
    count=0;
    memo=a[i];
    while(1){
      if(num%a[i]==0){
	ret[memo]=count;
	break;
      }
      if(ret[memo]!=0){
	ans+=ret[memo];
	break;
      }
      a[i]++;
      ans++;
      count++;
    }
  }
  cout<<ans<<endl;
  return 0;
}

