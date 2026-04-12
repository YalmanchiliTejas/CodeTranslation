#include <bits/stdc++.h>
using namespace std;

int main(){
	while(1){
		int n, av, max, min, sum = 0,s;
		cin>>n;
		if(n == 0) break;
			cin>>s;
			sum = s;
			max = s;
			min = s;
		for(int i = 1; i < n; i++){
			cin>>s;
			sum += s;
			if(s > max) max = s;
			if(s < min) min = s;
		}
		av = (sum - max - min)/ (n - 2);
		cout<<av<<endl;
	}
	
	return 0;
}


