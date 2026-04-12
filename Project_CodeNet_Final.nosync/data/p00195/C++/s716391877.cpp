#include<iostream>
using namespace std;
int main(){
	int sum[5];
	int s1,s2;
	while(cin >> s1 >> s2){
		if(s1==0 && s2==0) break;
		sum[0]=s1+s2;
		for(int i=1; i<5; i++){
			cin >> s1 >> s2;
			sum[i]=s1+s2;
		}
		int max=sum[0];
		char flag = 'A';
		for(int i=1; i<5; i++){
			if(sum[i] > max){
				max = sum[i];
				flag='A'+i;
			}
		}
		cout << flag << " ";
		cout << max << endl;
	}
	return 0;
}