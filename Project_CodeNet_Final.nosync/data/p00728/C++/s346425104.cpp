#include<iostream>
using namespace std;

int main(){
	int num;
	int score[105];
	int max = 0;
	int min = 10000;
	int sum=0;


	while(1){
		max = 0; min = 10000; sum = 0;
		for(int i=0; i < 100; i++){score[i] = 0;}

		cin >> num;

		if(num == 0) break;

		for(int i=0; i < num; i++){
			cin >> score[i];
			if(max <= score[i]) max = score[i];
			if(score[i] <= min) min = score[i];
			sum += score[i];
		}

		sum -= max; sum -= min;

		cout << sum/(num-2) << endl;
	}
	return 0;
}