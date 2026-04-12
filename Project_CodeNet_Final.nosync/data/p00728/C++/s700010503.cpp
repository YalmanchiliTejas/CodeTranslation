#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n,i,s,b,w,ans;
	while(true){
		scanf("%d",&n);
		if(n==0){break;}
		ans = 0;
		b = -1;
		w = 1001;
		for(i=0; i<n; i++){
			 cin >> s;
			 b = max(s,b);
			 w = min(s,w);
			 ans += s;
		}
		ans -= b;
		ans -= w;
		cout << (ans/(n-2)) << endl;
	}
	return 0;
}