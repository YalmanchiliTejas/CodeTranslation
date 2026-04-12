#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	while(1){
		int n;
		cin >> n;
		if(n == 0)
			break;
		
		
		vector <int> s(n);
		int M, m;
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
			if(i == 0){
				M = s[i];
				m = s[i];
			}
			else{
				M = max(M, s[i]);
				m = min(m, s[i]);
			}
		}
		
		sum -= M + m;
		
		
		cout << sum / (n - 2) << endl;
	}
	
	return 0;
}