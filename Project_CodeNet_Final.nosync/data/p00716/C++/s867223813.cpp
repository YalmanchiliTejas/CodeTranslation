#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


typedef struct {
	int type;
	double nenri;
	double minus;
} pattern;

int rishi=0;

int sim(int year,int money,int type,double nenri,double minus) {
	int rishi=0;

	for (int i=0;i<year;i++) {
		if(type==0)
			rishi+=money*nenri;
		else
			money+=money*nenri;

		money-=minus;
	}


	return money+rishi;
}

int main(void) {

	int m;


	cin >> m;

	for(int j=0;j<m;j++) {
		int shikin;

		int years;
		int n;
		
		cin >> shikin;
		cin >> years;
		cin >> n;

		vector<int> money;
		for(int i=0;i<n;i++) {
			pattern tmp;

			cin >> tmp.type >> tmp.nenri >> tmp.minus;
			money.push_back(sim(years ,shikin, tmp.type ,tmp.nenri ,tmp.minus));
		}

		sort(money.begin(),money.end(),greater<int>() );
		//cout << money[money.size()-1] << endl;
		cout << money[0] << endl;

	}


	return 0;
}