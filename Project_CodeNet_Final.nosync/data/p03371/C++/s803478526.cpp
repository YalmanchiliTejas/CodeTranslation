#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,x,y;
  	cin >> a >> b >> c >> x >> y;
  	int ans = a*x+b*y;
  	for (int i=0;i<=max(x,y);i++){
    	ans = min (ans,a*max(0,(x-i))+b*max(0,(y-i))+c*2*i);
    }
  	cout << ans << endl;
}