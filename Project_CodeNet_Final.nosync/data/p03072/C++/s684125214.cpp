#include<iostream>
using namespace std;

int main(){
	int num,i,k;
	int mountain_num = 1;
	int N[100];
	int count_flg;
	
	//入力	
	cin >> num;
	
	for (i = 0;i<num;i++){
		cin >> N[i];
	}

	
	
	//計算
	
	for ( i=1;i<num;i++){
		count_flg = 0;
		
		for(k = 0; k<i;k++)
		{
			if(N[k] - N[i] <= 0) 
			{
				
			}else{
				count_flg = 1;
			}
		}
		if(count_flg == 0) {
			mountain_num++;				
		}
		
	}
	
	//出力
	cout << mountain_num << endl;
	
		
	return 0;
}