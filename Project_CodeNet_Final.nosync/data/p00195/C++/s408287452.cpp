#include <iostream>
using namespace std;

int main() {
	int a[4];
	while(1){
		for(int i=0;i<5;i++){
			int tmp,TMP; cin >> tmp >> TMP;
			if(!tmp && !TMP) return 0;
			a[i]=tmp+TMP;
		}
		int n=0,tmp=a[0];
		for(int i=1;i<5;i++){
			if(a[i]>tmp) tmp=a[i],n=i;
		}
		char ch='A'; ch+=n;
		cout << ch << ' ' << tmp << '\n' ;
	}
}