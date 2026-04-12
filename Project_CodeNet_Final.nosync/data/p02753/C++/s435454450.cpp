#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 100003
int bas,son;
#define orta (bas+son)/2

int main(){
	string s;
	cin>>s;
	if(s[0] == s[1] and s[1] == s[2]){
		
			cout<<"No";
			return 0;
	}
	cout<<"Yes";
    return 0;
}
