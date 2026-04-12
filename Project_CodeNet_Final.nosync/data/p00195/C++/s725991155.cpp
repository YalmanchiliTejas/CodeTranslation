#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

int main(){
	
	int s1[5], s2[5];
	
	while(true){
		
		cin >> s1[0] >> s2[0];
		
		if(s1[0] == 0 && s2[0] == 0){
			break;
		}
		
		for(int i = 1; i < 5; i++){
			cin >> s1[i] >> s2[i];
		}
		
		int max = 0;
		int ans = 0;
		
		for(int i = 0; i < 5; i++){
			if(max < s1[i] + s2[i]){
				max = s1[i] + s2[i];
				ans = i;
			}
		}
		
		string ans_str = "A";
		
		ans_str[0] = 'A' + ans;
		
		cout << ans_str << " " << max << endl;
	}
	
	return 0;
}