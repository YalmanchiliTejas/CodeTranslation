#include <iostream>
#include <string>

using namespace std;

//YUIOPHJKLNM
bool isLeft(char c){
	string list = "yuiophjklnm";
	//stringのsize()はO(1)、char配列のstrlen(str)はO(n)
	for(int i=0;i<list.size();i++){
		if(list[i] == c){
			return true;
		}
	}
	return false;
}

int main(){
	while(true){
		string str;
		cin >> str;
		if(str == "#"){
			break;
		}
		int cnt = 0;//手の入れ替わる回数
		bool prev = isLeft(str[0]);//前のキーが左手だったらtrue
		for(int i=0;i<str.size();i++){//1から始めてもよい
			bool now = isLeft(str[i]);
			if(prev != now){
				cnt ++;
			}
			prev = now;
		}
		cout << cnt << endl;
	}
	return 0;
}