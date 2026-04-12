#include <iostream>
using namespace std;
string leftkey="qwertasdfgzxcvb";
string s;
bool r,l;
int cnt;
int main(){
	while(1){
		cin >>s;
		if(s=="#")break;
		cnt=0;
		r=l=false;
		for(int i=0;i<s.size();i++){
			for(int j=0;j<leftkey.size();j++){
				if(s[i]==leftkey[j]){
					if(r&&!l)cnt++;
					l=true;
					r=false;
					break;
				}else if(j==leftkey.size()-1){
					if(!r&&l)cnt++;
					l=false;
					r=true;
				}
			}
		}
		cout << cnt<<endl;
	}
	return 0;
}