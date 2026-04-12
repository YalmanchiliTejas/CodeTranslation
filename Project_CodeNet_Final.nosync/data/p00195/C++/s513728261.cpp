#include<iostream>
using namespace std;
int main(void){
	int a,b;
	while(1){
		int max=-1;
		char c[5];
		c[0]= 'A';
		c[1]= 'B';
		c[2]= 'C';
		c[3]= 'D';
		c[4]= 'E';
		int maxchar=0;
		
		for(int i=0;i<5;i++){
					cin >> a >> b;
			if(a == 0  && b == 0) break;
			else if(max < a+b){
				max =a+b;
				maxchar=i;
			}
		}
			if(a == 0 && b ==0) break;
		cout << c[maxchar] << " " << max <<endl;
				
	}
		
		}