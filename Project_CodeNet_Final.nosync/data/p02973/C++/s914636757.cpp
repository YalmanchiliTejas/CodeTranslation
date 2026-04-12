#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,a,ans=0;
  scanf("%d",&n);
  multiset <int> ms;
  multiset <int> :: iterator it;
  for(int i=0;i<n;++i){
    scanf("%d",&a);
    if(ms.empty()){
      ans++;
      ms.insert(a);
      continue;
    }
    it=ms.lower_bound(a);
      if(it!=ms.begin()){
      	--it;
        ms.erase(it);
      }
   	 else
       ans++;
      ms.insert(a);
  }
  printf("%d\n",ans);
  return 0;
}