#include <bits/stdc++.h>
using namespace std;

int lr(char a){
	//l = 0, r = 1
	if(a == 'q') return 0;
	else if(a == 'w') return 0;
	else if(a == 'e') return 0;
	else if(a == 'r') return 0;
	else if(a == 't') return 0;
	
	else if(a == 'a') return 0;
	else if(a == 's') return 0;
	else if(a == 'd') return 0;
	else if(a == 'f') return 0;
	else if(a == 'g') return 0;
	
	else if(a == 'z') return 0;
	else if(a == 'x') return 0;
	else if(a == 'c') return 0;
	else if(a == 'v') return 0;
	else if(a == 'b') return 0;
	else return 1;
}

int main(){
while(1){	
	
	string s;
	int cnt = 0;
	cin >> s;
	if(s == "#") break;
	int len = s.size();
	int past = lr(s[0]);
	for(int i = 1; i < len; i++){
		if(past != lr(s[i])) cnt += 1;
		past = lr(s[i]);
	}
	
	cout << cnt << endl;
	
}//end
	return 0;
}
