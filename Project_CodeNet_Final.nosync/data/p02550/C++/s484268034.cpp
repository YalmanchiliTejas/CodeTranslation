#include <iostream>
#include <vector>
using namespace std;

int main(){
  long n;
  long x, m;
  cin >> n >> x >> m;
  vector<long>a(m+100), ar(m+100);
  vector<long>numchk(m, -1); // 最後にその数字があった場所
  a[0]=x;
  ar[0]=0;
  numchk[x]=0;
  long loopstart, loopcnt;
  for(int i=1; i<=m; i++){
    a[i] = (a[i-1]*a[i-1])%m;
	if(numchk[a[i]]>=0){
      loopstart = numchk[a[i]];
      loopcnt = i-numchk[a[i]];
      ar[i]=ar[i-1]+a[i-1];
      break;
    }
    else numchk[a[i]]=i;
    ar[i]=ar[i-1]+a[i-1];
  }
  // for(int i=0; i<m; i++)cerr << ar[i] << ' ';
  if(n<=loopstart){
    cout << ar[n];
  }
  else{
    long ret=ar[loopstart];
    ret += (n-loopstart)/loopcnt*(ar[loopstart+loopcnt]-ar[loopstart]);
    ret += ar[loopstart+(n-loopstart)%loopcnt]-ar[loopstart];
    cout << ret;
  }
  return 0;
}