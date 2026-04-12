#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	bool flag = true;
	int n,i,win,draw,lose,point[10];
	string str[10];
	while(cin >> n && n){
		for(i=0;i<n;i++){
			cin >> str[i] >> win >> lose >> draw;
			point[i] = (win*3)+(draw*1);
		}
		if(flag == false) cout << "\n";
		for(i=0;i<n-1;i++){
			for(int j=n-1;i<j;j--){
				if(point[j-1] < point[j]){
					swap(str[j-1],str[j]);
					swap(point[j-1],point[j]);
				}
			}
		}
		for(i=0;i<n;i++){
			cout << str[i] << "," << point[i] << endl;
		}
		flag = false;
	}
	return 0;
}