#include <iostream>
#include <string>

using namespace std;

int main(void){
	while(1){
		string moji;
		cin >> moji;
		if(moji=="#") break;
		
		char left[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
		char right[] = {'y','u','i','o','p','h','j','k','l','n','m'};
		bool r=false;
		for(int k=0; k<11; k++){
			if(moji[0]==right[k]){
				r=true;
			}
		}
		
		int count=0;
		for(int i=0; i<moji.size(); i++){
			bool l=true;
			for(int j=0; j<11; j++){
				if(moji[i]==right[j]){
					l=false;
					if(!r){
						r=true;
						count++;
						break;
					}
				}
			}
			if(l&&r){
				r=false;
				count++;
			}
		}
		
		cout << count << endl;
	}
	return 0;
}