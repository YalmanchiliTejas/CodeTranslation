#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,c,x;
	while(cin >> n >> a >> b >> c >> x and !(n==0 and a==0 and b==0 and c==0 and x==0)){
		vector<int> y(n);
		for(int i=0;i<n;i++){
			cin >> y[i];
		}
		int cnt = 0, key = 0;
		while(cnt <= 10000){
			if(y[key]==x){
				key++;
			}
			if(key==n) break;
			x = (a*x + b) % c;
			cnt++;
		}
		if(key==n){
			cout << cnt << endl;
		}else{
			cout << -1 << endl;
		}
	}
}
