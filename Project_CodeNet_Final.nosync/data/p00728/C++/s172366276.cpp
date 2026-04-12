#include<iostream>
using namespace std;

int main(void){
	int judg;
	
	while(1){
		cin >> judg;
		if(judg==0)break;

		//点数入力
		int *score = new int[judg];
		for(int i=0; i<judg; i++)
			cin >> score[i];
		
		//最高点最低点求める
		int max=0,min=0;
		for(int i=0; i<judg; i++){
			if( score[max]<score[i] ) max=i;
			if( score[min]>score[i] ) min=i;
		}
		
		//平均点求める
		int avg=0;
		for(int i=0; i<judg; i++){
			if(i!=max&&i!=min)
				avg+=score[i];
		}
		avg = avg/(judg-2);

		cout << avg << endl;
	}
}