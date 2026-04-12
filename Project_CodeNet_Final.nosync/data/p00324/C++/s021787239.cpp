#include<cstdio>
#include<map>
using namespace std;
int main(){
  int n,ma=0;
  long long d[200001],cnt=0;
  map<long long,int> mp;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lld",&d[i]);
    cnt += d[i];
    if(mp.find(cnt) == mp.end()){
      if(cnt == 0) ma = i+1;
      else mp[cnt]=i;
    }else ma = max(ma,i-mp[cnt]);
  }
  printf("%d\n",ma);
  return(0);
}

