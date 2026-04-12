#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	while(true){
		string ss;
		cin >> n;
		if(n==0){
			break;
		}

		int top = 1;//上
		int bot = 6;//下
		int s[4] = {2,3,5,4};
		int ans=1;

		for(int i=0;i<n;i++){
			cin >> ss;
			if(ss == "North"){
				int buf = top;
				top = s[0];
				s[0] = bot;
				bot = s[2];
				s[2] = buf;
				ans += top;
			}
			if(ss == "East"){
				int buf = top;
				top = s[3];
				s[3] = bot;
				bot = s[1];
				s[1] = buf;
				ans += top;
			}
			if(ss == "West"){
				int buf = top;
				top = s[1];
				s[1] = bot;
				bot = s[3];
				s[3] = buf;
				ans += top;
			}
			if(ss == "South"){
				int buf = top;
				top = s[2];
				s[2] = bot;
				bot = s[0];
				s[0] = buf;
				ans += top;
			}
			if(ss == "Right"){
				int buf = s[0];
				s[0] = s[1];
				s[1] = s[2];
				s[2] = s[3];
				s[3] = buf;
				ans += top;
			}
			if(ss == "Left"){
				int buf = s[3];
				s[3] = s[2];
				s[2] = s[1];
				s[1] = s[0];
				s[0] = buf;
				ans += top;
			}
		}
		cout << ans << endl;
	}
}