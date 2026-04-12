#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn];
int main(){
  int n;scanf("%d",&n);
  int l=1,r=n;
  for(int i=1;i<=n;++i)scanf("%d",a+i);
  int flag=0;
  for(int i=n;i>=1;--i){
    if(flag){
      b[r--]=a[i];      
    }else{

      b[l++]=a[i];
    }
    flag^=1;
  }
  for(int i=1;i<=n;++i)printf("%d ",b[i]);
  return 0;
}
