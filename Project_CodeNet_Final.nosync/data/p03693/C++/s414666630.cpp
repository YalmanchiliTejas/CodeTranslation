#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	a = 0;
	string str = "";
	char c2;
	for(int i =0;i<3;i++){
		cin >> c2;
		str.push_back(c2);
	}
	a = stoi(str);
	
	if(a%4 == 0)
		cout<<"YES";
	else
		cout<<"NO";
	
}