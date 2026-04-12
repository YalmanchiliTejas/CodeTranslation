#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string migi = "yuiophjklnm";
	string hidari = "qwertasdfgzxcvb";
	string s;
	int count;
	int i,j;
	int t; /* 0 右　１左 */

	
	while(1){

		cin >> s;
		if(s=="#") break;
		
		t = -1;
		count = 0;
		for(i=0;i<s.length();i++){
			
			
			for(j=0;j<migi.length();j++) {
				
				if (s[i]==migi[j]) {
					if (t==1) {
						
						count++;
						t=0;
						break;
					}
					else if( t==-1){
	//					cout << "a";
						t=0;
						break;
					}
					else break;
				}
			}
	//		cout << j  << endl;
			if (j==migi.length()){
				if (t==0) {
	//				cout << "b";
					count++;
					t=1;
				}
				else if(t==-1) {
					t=1;
				}
			}

		}
			

		cout << count << endl;
	}

	return 0;
}