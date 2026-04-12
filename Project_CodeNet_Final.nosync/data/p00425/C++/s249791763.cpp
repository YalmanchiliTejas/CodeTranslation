#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,tmp;
	string str;
	while(cin >> n && n){
		int x = 1,y = 2,z = 3,tortal = 1;
		for(int i=0;i<n;i++){
			cin >> str;
			if(str == "North"){
				tmp = y;
				y = 7 - x;
				x = tmp;
				tortal += x;
			}
			else if(str == "South"){
				tmp = x;
				x = 7 - y;
				y = tmp;
				tortal += x;
			}
			else if(str == "West"){
				tmp = z;
				z = 7 - x;
				x = tmp;
				tortal += x;
			}
			else if(str == "East"){
				tmp = x;
				x = 7 - z;
				z = tmp;
				tortal += x;
			}
			else if(str == "Right"){
				tmp = z;
				z = 7 - y;
				y = tmp;
				tortal += x;
			}
			else if(str == "Left"){
				tmp = y;
				y = 7 - z;
				z = tmp;
				tortal += x;
			}
		}
		cout << tortal << endl;
	}
	return 0;
}