#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string d;
	cin>>d;
	int countA = 0;
	int countB =0;
	for(auto s : d){
		if(s== 'B') countB++;
		else countA++;
		}
	if(countB==3 or countA==3) cout<<"No";
	else cout<<"Yes";	
	
	return 0;
	}
