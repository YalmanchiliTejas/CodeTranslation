#include <bits/stdc++.h>
using namespace std;

int main(){

  int N, n;
  uint64_t X;
  uint64_t paty[51];
  uint64_t mx=1,mn=1;
  uint64_t ans=0,ans2=0,num;
  paty[0]=1;
  cin >> N >> X;
  n = N;

  for(int i=1; i<=N; i++) mx = 2*mx+3;
  for(int i=1; i<51; i++) paty[i] = paty[i-1]*2+1;
  while(mn!=X&&mx!=X){
    num = (mx+mn)/2;
    if(num==X){
      ans+=paty[--N]+1;
      mn = num;
      break;
    }else if(num<X){
      mn = num;
      ans+=paty[--N]+1;
    }else{
      mx = num;
      ans2+=paty[--N]+1;
    }
    mx--;
    mn++;
  }

  if(mn==X){
    if(mx-mn<2) ans++;
    cout << ans << endl;
  } else {
  if(mx-mn<2) ans2++;
    cout << paty[n]-ans2 << endl;
  }

  return 0;
}
