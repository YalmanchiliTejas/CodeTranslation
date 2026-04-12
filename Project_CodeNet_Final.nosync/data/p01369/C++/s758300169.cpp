#include<iostream>
#include<string>
using namespace std;
int main(){
	for(;;){
		string word;
		int hand = 0, sum = 0;
		getline(cin,word);
		if(word == "#"){break;}
		for(int i=0; i<word.size(); i++){
			int flag = 2;
			if(word[i] == 'q'){flag = 1;}
			if(word[i] == 'w'){flag = 1;}
			if(word[i] == 'e'){flag = 1;}
			if(word[i] == 'r'){flag = 1;}
			if(word[i] == 't'){flag = 1;}
			if(word[i] == 'a'){flag = 1;}
			if(word[i] == 's'){flag = 1;}
			if(word[i] == 'd'){flag = 1;}
			if(word[i] == 'f'){flag = 1;}
			if(word[i] == 'g'){flag = 1;}
			if(word[i] == 'z'){flag = 1;}
			if(word[i] == 'x'){flag = 1;}
			if(word[i] == 'c'){flag = 1;}
			if(word[i] == 'v'){flag = 1;}
			if(word[i] == 'b'){flag = 1;}
			if(!hand){hand = flag;}
			else if(hand != flag){hand = flag; sum++;}
		}
		cout <<sum<<endl;
	}
	return 0;
}