#include<iostream>
#include<string>
using namespace std;

int main(){
	char type[] = {'y','u','i','o','p','h','j','k','l','n','m'};
	string str;
	while(cin >> str , str != "#"){
		int now = -1,i;
		int ans = 0;
		int len = str.size();
		for(int k=0;k<len;k++){
			for(i=0;i<=10;i++){
				if(str[k] == type[i]){
					if(now == 1) ans++;
					now = 0;
					break;
				}
			}
			if(i == 11) {
				if(now == 0) ans++;
				now = 1;
			}
		}
		cout << ans << endl;
	}
}