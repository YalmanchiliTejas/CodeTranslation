#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int n,a[maxn],b[maxn];
long long res;
void calc(){
  int mid=n/2,l=0,r=n-1,flg_i=0,flg_o=0,count_o=0,L,R;
  b[mid]=a[l++];L=mid;R=mid;
  while(l<=r){
    if(flg_o==0) flg_i==0 ? b[++R]=a[r--] : b[++R]=a[l++] , flg_i^=1;
    else flg_i==0 ? b[--L]=a[r--] : b[--L]=a[l++] , flg_i^=1;
    if(++count_o==2) flg_o^=1 , count_o=0;
  }
  long long tmp=0;
  for(int i=L;i<R;i++)tmp+=abs(b[i]-b[i+1]);
  res=max(res,tmp);
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  sort(a,a+n);
  if(n==2) {printf("%d",a[1]-a[0]); return 0;}
  calc();reverse(a,a+n);calc();
  printf("%lld",res);
  return 0;
}