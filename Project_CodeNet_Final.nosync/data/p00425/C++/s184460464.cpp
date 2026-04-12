#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	int temp;
	string str;

	while(1){
		int north = 5;
		int east = 3;
		int top = 1;
		int ans = 1;
		cin >> n;
		if(n == 0)break;

		for(int i=0;i<n;++i){
			cin >> str;
			if(str == "North"){
				temp = top;
				top = 7-north;
				north = temp;
			}
			else if(str == "East"){
				temp = top;
				top = 7-east;
				east = temp;
			}
			else if(str == "West"){
				temp = east;
				east = 7-top;
				top = temp;
			}
			else if(str == "South"){
				temp = north;
				north = 7-top;
				top = temp;
			}
			else if(str == "Right"){
				temp = north;
				north = 7-east;
				east = temp;
			}
			else if(str == "Left"){
				temp = east;
				east = 7-north;
				north = temp;
			}
			ans += top;
		}
		cout << ans << endl;
	}
	return 0;
}