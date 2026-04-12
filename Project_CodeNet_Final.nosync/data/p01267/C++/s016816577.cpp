#include<bits/stdc++.h>

using namespace std;

int main(){

  while(1){
	int n,a,b,c,x;
	
	cin >> n >> a >> b >> c >> x;
	if(n == 0 && a == 0 && b == 0 && c == 0 && x == 0)
	  break;
	
	vector<int> y(n);

	for(int i = 0;i < n; ++i)
	  cin >> y[i];

	int f = 0;
	int cnt = 0;
	
	while(1){

	  if(x == y[cnt]){
		cnt++;
		if(cnt == n)
		  break;
	  }
	  
	  x = (a * x + b) % c;
	  f++;
	  
	  if(f > 10000)
		break;
	}
	
	  if(f > 10000)
		cout << -1 << endl;
	  else
		cout << f << endl;
	
  }

  return 0;
  
}

