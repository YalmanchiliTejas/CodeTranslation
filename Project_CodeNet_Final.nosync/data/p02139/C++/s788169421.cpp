#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n,q;
  cin >> n >> q;
  LL nowidx=0;
  LL k;
  int qn;
  for(int i=0;i<q;i++){
    cin >> qn >> k;
    if(qn==0){
      cout << (nowidx+k-1)%n+1 << endl;
    }else{
      nowidx=(nowidx+k)%n;
    }
  }
  return 0;
}

