#include <iostream>
#include <string>
using namespace std;

int main(){
	string lefth("qwertasdfgzxcvb");
	string righth("yuiophjklnm");
	bool flag = false; /* ?????????????????? */
	int ans;
	string str;
	while(cin >> str, str != "#"){
		ans = 0;
		int len = str.size();
		if(lefth.find(str[0]) != -1){
			flag = true;
		}
		if(righth.find(str[0]) != -1){
			flag = false;
		}
		for(int i = 1; i < len; ++i){
			if(!flag){
				if(lefth.find(str[i]) != -1){
					flag = true;
					++ans;
				}
			}else{
				if(righth.find(str[i]) != -1){
					flag = false;
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
}