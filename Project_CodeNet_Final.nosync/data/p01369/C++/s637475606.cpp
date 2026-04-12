#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

const char leftKey[]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
const char rightKey[]={'y','u','i','o','p','h','j','k','l','n','m'};

int main(){
	
	char str[32];
	int inpStrNum;
	int cnt;
	int lr,foundKey;
	
	while(true){
		fill(str,str+32,'\0');
		cnt=0;
		
		lr=true;//leftならfalse、rightならtrue
		
		cin>>str;
		
		if(str[0]=='#'){
			break;
		}
		
		lr=1;
		for(int i=0;i<15;i++){
			if(str[0]==leftKey[i]){
				lr=0;
				break;
			}
		}
		
		for(int i=1;i<strlen(str);i++){
			for(int j=0;j<15;j++){
				if(str[i]==leftKey[j] && lr==1){
					cnt++;
					//foundKey=true;
					lr=0;
					break;
				}
			}
			for(int j=0;j<11;j++){
				if(str[i]==rightKey[j] && lr==0){
					cnt++;
					lr=1;
					break;
				}
			}
		}
		
		cout<<cnt<<endl;
	}
}