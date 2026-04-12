#include<iostream>
#include<string>
using namespace std;


int main(void){
	int count;
	while(cin >> count){
		if (count == 0) break;
		else{

		int da[3];
		da[0] =1,da[1] =2,da[2] = 3;
		int ans=1,b=0;
		string str;
		int i;
			for(i=0;i<count;i++){
				cin >> str;
				if(str == "North"){
					b = da[1];
					da[1] = 7-da[0];
					da[0] = b;
					ans += da[0];
				}
				if(str == "East"){
					b = da[2];
					da[2] = da[0];
					da[0] = 7-b;
					ans += da[0];
				}
				if(str == "West"){
					b = da[0];
					da[0] = da[2];
					da[2] = 7-b;
					ans += da[0];
				}
				if(str == "South"){
					b = da[1];
					da[1] = da[0];
					da[0] = 7-b;
					ans += da[0];
				}
				if(str == "Right"){
					b = da[1];
					da[1] =da[2];
					da[2] = 7-b;
					ans += da[0];
				}
				if(str == "Left"){
					b = da[1];
					da[1] = 7-da[2];
					da[2] = b;
					ans += da[0];
				}
			}cout << ans << endl;
		}
       }
}