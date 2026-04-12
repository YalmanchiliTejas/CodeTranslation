#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	
	while(1){
		cin >> n;
		if(n==0) break;
		int s[n];
		
		for(int i=0;i<n;i++)
			cin >> s[i];
		
		sort(s,s+n);
		
		int sum=0;
		
		for(int i=1;i<n-1;i++){
			sum += s[i];
		}
		
		cout << sum/(n-2) << endl;
	}
	
	return 0;
}
	
