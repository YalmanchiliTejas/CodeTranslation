#include<iostream>
using namespace std;

int main(){
  int n,a,b,c,x;
  int cnt,y;

  while(1){
    cin >> n >> a >> b >> c >> x;
    if(!n && !a && !b && !c && !x)break;

    cnt = 0;
    for(int i=0;i<n;i++){
      cin >> y;
      while(1){
	if(y == x)break;
	cnt++;
	x = (a * x + b) % c;
	if(cnt>10000)break;
      }
      if(i==n-1)break;
      cnt++;
      x = (a * x + b) % c;
    }

    if(cnt>10000)cout << -1 << endl;
    else cout << cnt << endl;
  }
}