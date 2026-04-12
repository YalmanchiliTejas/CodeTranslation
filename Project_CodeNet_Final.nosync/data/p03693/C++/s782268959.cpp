/*
	Copyright: razouq (c)
	Author: Anass BENDARSI
	Date: 10/06/2017 12:00:44
	flamers will **** you
*/
#include<bits/stdc++.h>
//#include<flamers.h>
#define ull unsigned long long
using namespace std;

int main(){
	string c, str = "";
	for(int i = 0; i < 3; i++){
		cin>>c;
		str += c;
	}
	int n = stoi(str);
	if(n % 4 == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
