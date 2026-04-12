#include <iostream>
using namespace std;

int main(){
	while(1){
		int s1,s2;
		int maxc=0;
		int max=0;
		for(int i=0;i<5;i++){
			cin >> s1 >> s2;
			if(!s1&&!s2)return 0;
			if(s1+s2>max){
				max = s1 + s2;
				maxc = 'A'+i;
			}
		}
		cout << (char)maxc << " " << max << endl;
	}
}