#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<int> ans;
string migi = "yuiophjklnm";
map<char,bool> te;

void setmap(void);
int main(){
	setmap();
	while(1){
		string str;
		cin >> str;
		if(str == "#") break;
		bool now = te[str[0]];
		int count = 0;
		for(int i = 1;i < str.size();i++){
			if(now == te[str[i]]);
			else{count++;now = te[str[i]];}
		}
		ans.push_back(count);
	}
	for(int i = 0;i < ans.size();i++) cout << ans[i] << endl;
}

void setmap(void){
	for(int i = 0;i < 26;i++){
		char al = 'a' + i;
		te[al] = true;
		for(int j = 0;j < migi.size();j++){
			if(migi[j] == al){
				te[al] = false;
				break;
			}
		}
	}
}