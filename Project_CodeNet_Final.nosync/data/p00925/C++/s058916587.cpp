#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n;
	cin >> n;
	
	int ncal = s[0] -'0';
	for(int i = 2;i < s.size();i+=2){
		if(s[i-1] == '+'){
			ncal += s[i] - '0';
		}else{
			ncal *= s[i] - '0';
		}
	}
	
	int rcal = 0;
	int tmulti = 1;
	for(int i = 0;i < s.size()-1;i+=2){
		if(s[i+1] == '+'){
			rcal += tmulti * (s[i] - '0');
			tmulti = 1;
		}else{
			tmulti *= s[i] - '0';
		}
	}
	rcal += tmulti * (s[s.size()-1] - '0');
	
	if(n == rcal && n != ncal){
		cout << "M" << endl;
	}else if(n != rcal && n == ncal){
		cout << "L" << endl;
	}else if(n == rcal && n == ncal){
		cout << "U" << endl;
	}else{
		cout << "I" << endl;
	}
	return 0;
}
