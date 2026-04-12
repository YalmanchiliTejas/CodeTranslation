
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;


bool solve(){
	string a = "yuiophjklnm";	// b = "qwertyasdfgzxcvb";
	int asize = a.size();
	
	while(1){
		string str;
		cin>> str;
		if(str == "#") break;
		
		int ans = 0;
		int rl_pre = 0;
		for(int j=0;j<asize;j++){
			if(str[0] == a[j]){
				rl_pre = 1;
				break;
			}
		}
		for(int i=1;i<str.size();i++){
			int rl_crr = 0;
			for(int j=0;j<asize;j++){
				if(str[i] == a[j]){
					rl_crr++;
					break;
				}
			}
			if(rl_pre != rl_crr){
				rl_pre = rl_crr;
				ans++;
			}
		}
		cout<< ans<< endl;
	}
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

 