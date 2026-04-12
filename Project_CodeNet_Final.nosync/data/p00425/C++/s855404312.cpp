#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int ans = 1;
		int s[3]={1,2,3};
		for(int i=0;i<n;i++){
			string str;
			cin >> str;
			if(str=="North"){
				int tmp = s[0];
				s[0] = s[1];
				s[1] = 7 - tmp;
			}
			else if(str=="East"){
				int tmp = s[2];
				s[2] = s[0];
				s[0] = 7 - tmp;
			}
			else if(str=="West"){
				int tmp = s[0];
				s[0] = s[2];
				s[2] = 7 - tmp;
			}
			else if(str=="South"){
				int tmp = s[1];
				s[1] = s[0];
				s[0] = 7 - tmp;
			}
			else if(str=="Right"){
				int tmp = s[1];
				s[1] = s[2];
				s[2] = 7 - tmp;
			}
			else {
				int tmp = s[2];
				s[2] = s[1];
				s[1] = 7 - tmp;
			}
			ans += s[0];
		}
		cout << ans << endl;
	}
}