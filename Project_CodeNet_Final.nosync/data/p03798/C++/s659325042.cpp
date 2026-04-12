#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <climits>

using namespace std;

string s;
char ans[100005];
int n;

bool isValidAtPos(int x){
	int y = (x+1)%n;
	if(ans[x] == 'S'){
		if(s[x] == 'o' && ans[y] == ans[x-1])
			return true;
		else if(s[x] == 'x' && ans[y] != ans[x-1])
			return true;
	}else{
		if(s[x] == 'o' && ans[y] != ans[x-1])
			return true;
		else if(s[x] == 'x' && ans[y] == ans[x-1])
			return true;
	}
	return false;
}

bool isValid(){
	int i;
	for(i = 1; i<n-2; i++){
		if(ans[i] == 'S'){
			if(s[i] == 'o')
				ans[i+1] = ans[i-1];
			else
				ans[i+1] = ans[i-1]=='W'?'S':'W';
		}else if(ans[i] == 'W'){
			if(s[i] == 'o')
				ans[i+1] = ans[i-1]=='S'?'W':'S';
			else
				ans[i+1] = ans[i-1];
		}
	}
	return isValidAtPos(n-2) && isValidAtPos(n-1);
}

bool makeCase(char a, char b){
	int i;
	for(i = 0; i<n; i++)
		ans[i] = '0';
	ans[0] = a;
	ans[1] = b;
	if(ans[0] == 'S'){
		if(s[0] == 'o')
			ans[n-1] = ans[1];
		else ans[n-1] = b=='W'?'S':'W';
	}else{
		if(s[0] == 'o')
			ans[n-1] = b=='W'?'S':'W';
		else ans[n-1] = ans[1];
	}
	return isValid();
}

int main(){
	int i;
	cin>>n;
	cin>>s;
	if(makeCase('S','W') || makeCase('S','S') || makeCase('W','S') || makeCase('W', 'W')){
		for(i = 0; i<n; i++)
			cout<<ans[i];
		cout<<endl;
	}else cout<<"-1"<<endl;
	return 0;
}