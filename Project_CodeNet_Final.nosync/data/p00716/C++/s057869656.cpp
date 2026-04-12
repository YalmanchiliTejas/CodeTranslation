#include <iostream>

using namespace std;

int main(){
	int dataSet, money, year, n, hukuriFlag , charge;
	int money2,risi,answer;
	double nenri;

	//f[^ZbgÌüÍ
	cin >> dataSet;

	//f[^Zbg¾¯üÍ³¹é
	for(int i=0 ; i<dataSet ; i++){
		//ÏÌú»
		answer = 0;

		//money:ú^pàÊ  year:^pN  n:^pû@ÌíÞ
		cin >> money >> year >> n;

		//^pû@ÌíÞ¾¯[v³¹é
		for(int j=0 ; j<n ; j++){
			//hukuriFlag:Por¡  nenri:N¦  chargeNÌè¿  
			cin >> hukuriFlag >> nenri >> charge;

			money2 = money;
			risi = 0;

			if(hukuriFlag==1){//¡¾Á½ç
				//^pN¾¯[v³¹é
				for(int y=0 ; y<year ; y++){
					money2 += money2*nenri;
					money2 -= charge;
				}
				//ÅIàªå«©Á½ç¦Éüêé
				if(answer<money2)answer = money2;
			}
			else{//P¾Á½ç
				//^pN¾¯[v³¹é
				for(int y=0 ; y<year ; y++){
					risi += money2*nenri;
					money2 -= charge;
				}
				//ÅIàªå«©Á½ç¦Éüêé
				if(answer<money2+risi)answer = money2 + risi;
			}
		}

		//¦ÌoÍ
		cout << answer << endl; 
	}

	return 0;
}