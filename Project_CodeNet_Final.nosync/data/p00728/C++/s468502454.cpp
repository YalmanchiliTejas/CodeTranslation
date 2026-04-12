#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(1){
		int a, max=-1, min=100000, sum=0, ans;
		cin >> n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin >> a;
			if(a<min) min=a;
			if(a>max) max=a;
			sum += a;
		}
		ans = (sum-(max+min))/(n-2);
		cout << ans << endl;
	}
}
