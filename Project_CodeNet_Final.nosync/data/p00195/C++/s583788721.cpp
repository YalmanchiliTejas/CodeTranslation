#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
	while(1){
		int a,b,c;
		int max,name=0;
		char na[6]="ABCDE";
		cin >> b >> c;
		if(b==0 && c==0)break;
		max=b+c;
		for(a=1;a<=4;a++){
			cin >> b >> c;
			if(b+c>max)name=a,max=b+c;
		}
		cout << na[name] << " " << max << endl;
	}
	return 0;
}