#include <iostream>
#include <string>
using namespace std;
int main(){
		string L("qwertasdfgzxcvb");
		string R("yuiophjklnm");
		string P;
		int fraga =0;
		int fragb =0;
		int left=L.length();
	while(1){
		int counter = 0;
		cin >>P;
		int length = P.length();
		if (P=="#")break;
		for(int i =0;i<length;i++){
			for(int j = 0;j<left;j++){
				if(P[i]==L[j]) {
					fraga=0;
					break;
				}
				else fraga=1;
			}
			if((fraga!=fragb)&&(i!=0)) counter+=1;
			fragb = fraga;
		}
		cout << counter<<endl;


	}


	return 0;
}