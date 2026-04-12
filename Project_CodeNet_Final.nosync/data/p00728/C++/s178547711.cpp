#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int ninzuu;
	while(cin >> ninzuu && ninzuu != 0){
		int max_value=-1;
		int min_value=1001;
		int sum=0;
		int average;
		for(int i=0;i<ninzuu;i++){
			int tmpNum;
			cin >> tmpNum;
			max_value = max(tmpNum,max_value);
			min_value = min(tmpNum,min_value);
			sum += tmpNum;
		}
		sum -= (max_value + min_value);
		average = sum / (ninzuu - 2);
		cout << average << endl; // 出力
	}
}