#include<bits/stdc++.h>
using namespace std;



int main(){
	int n,a,b,sum,cnt=0;
	cin >> n >> a >> b;
	sum=b;
	while(1){
		if(n<sum+a+b) break;
		sum+=a+b;
		cnt++;
	}
	
	cout << cnt << endl;
	return 0;
}