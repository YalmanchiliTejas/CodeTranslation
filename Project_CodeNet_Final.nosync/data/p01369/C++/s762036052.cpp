#include<iostream>
#include<string>

using namespace std;

int check(char in){
	string left = "qwertasdfgzxcvb";
	for(int i = 0; i < left.size(); i++){
		if(in == left[i]) return 1;
	}
	return 0;
}

int main(){

	string in;
	while(cin >> in && in != "#"){
		int sum = 0;
		int status = 0;
		if(check(in[0])) status = 1;

		for(int i = 1; i < in.size(); i++){
			if(check(in[i])){
				if(!status){
					sum++;
					status = 1;
				}
			}else{
				if(status){
					sum++;
					status = 0;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}