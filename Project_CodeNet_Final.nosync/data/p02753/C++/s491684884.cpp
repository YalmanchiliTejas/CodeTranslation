#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long int ll;
using namespace std;
int main(){
	io;
	char s[3];
	cin >> s;
	bool fa = 0,fb = 0;
	for(int i = 0;i < 3;++i){
		if(s[i] == 'A'){
			fa = 1;
		}
		else{
			fb = 1;
		}
	}
	if(fa && fb){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0; 
}