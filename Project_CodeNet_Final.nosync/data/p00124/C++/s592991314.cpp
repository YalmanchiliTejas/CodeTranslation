#include<iostream>
#include<string>
using namespace std;

int main(){
	int n,po;
	int score[10];
	string name[10];
	int d[]={3,0,1};
	int cou=0;
	while(1){
		cin >> n;
		if(n==0) break;
		if(cou != 0) cout << endl;
		for(int i=0;i<n;i++){
			cin >> name[i];
			score[i] = 0;
			for(int j=0;j<3;j++){
				cin >> po;
				score[i] += po * d[j];
			}
		}
		int top;
		for(int i=0;i<n;i++){
			top = 0;
			for(int j=1;j<n;j++){
				if(score[top]<score[j]){
					top = j;
				}
			}
			cout << name[top] << "," << score[top] << endl;
			score[top] = -1;
		}
		cou++;
	}
}