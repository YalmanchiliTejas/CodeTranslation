#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int left(char ch){
	if(ch=='q'||ch=='w'||ch=='e'||ch=='r'||ch=='t'||ch=='a'||ch=='s'||ch=='d'||ch=='f'||ch=='g'
		||ch=='z'||ch=='x'||ch=='c'||ch=='v'||ch=='b'){
			return 1;
	}
	else
		return 0;
}

int main(){

	string str;
	while(cin>>str&&!(str=="#")){
		int lf=left(str[0]);
		int cnt=0;
		for(int i = 1; i < str.size(); i++){
			int res=left(str[i]);
			if(res^lf){
				lf=res;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}