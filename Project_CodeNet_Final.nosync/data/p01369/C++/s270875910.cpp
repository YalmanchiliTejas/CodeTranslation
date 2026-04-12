#include<iostream>

using namespace std;

int main(){

	int data[26]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};

	string str;
	while(cin>>str){
		if(str.at(0)=='#')break;
		int cnt=0;
		for(int i=0;i<str.size();i++){
			int state = data[str.at(i)-'a'];
			if(i==str.size()-1)break;

			while(state == data[str.at(i+1)-'a']){
				i++;
				if(i==str.size()-1){
					break;
				}
			}
			
			if(i==str.size()-1){
				break;
			}
			cnt++;
		}
		cout<<cnt<<endl;

	}

	return 0;
}