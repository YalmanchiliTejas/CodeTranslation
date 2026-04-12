#include<bits/stdc++.h>

//短縮
#define rep(i,n) for(int i=0;i<(n);++i)
//sort()用
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int aa=0,bb=0,cc=0; //ccは偶数
  int cc_max;
  if(X>=Y) cc_max = X;
  else cc_max = Y;
  int min;
  for(cc=0;cc <= cc_max*2;cc+=2){
    aa=X-(cc/2);
    bb=Y-(cc/2);
    if(aa<0) aa=0;
    if(bb<0) bb=0;
    int answer = A*aa + B*bb + C*cc;
    if(cc==0) min = answer;
    if(answer<min) min = answer;
  }

  cout << min << endl;
  return 0;
}
