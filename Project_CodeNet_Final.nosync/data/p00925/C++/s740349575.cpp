#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calc(string s, int type){
	int cutA=-1, cutM=-1;
	for(int i=0; i<(int)s.length(); i++){
		if(s[i]=='+') cutA = i; 
		if(s[i]=='*') cutM = i;
	}
	if(cutA==-1 && cutM==-1){
		return stoi(s);
	}else if(cutA==-1 || (type==0 && cutM>cutA)){
		return calc(s.substr(0,cutM), type) * calc(s.substr(cutM+1, s.length()-cutM), type);
	}else{
		return calc(s.substr(0,cutA), type) + calc(s.substr(cutA+1, s.length()-cutA), type);
	}
}

int main(){
	string str;
	int ans;
	cin >> str >> ans;

	if(ans == calc(str,0)){
		if(ans == calc(str, 1)){
			cout << "U" << endl;
		}else{
			cout << "L" << endl;
		}
	}else{
		if(ans == calc(str, 1)){
			cout << "M" << endl;
		}else{
			cout << "I" << endl;
		}
	}
	return 0;
}