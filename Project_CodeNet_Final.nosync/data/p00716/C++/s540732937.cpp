#include <iostream>
#include <vector>
using namespace std;


struct  ways
{
	int tf;   /*  0 = tanri  1 = fukuri */
	double nenri;
	int tesu;
};


int tanri(int money, int year, ways w);
int fukuri(int money, int year, ways w);


int main(void)
{
	int m;


	int money;
	int year;
	int n;
	ways v;

	int i1,i2;

	int mon;
	int max;

	cin >> m;

	for(i1=0;i1<m;i1++){

		cin >> money;
		cin >> year;
		cin >> n;

		max = 0;

		for(i2=0;i2<n;i2++){
			cin >> v.tf >> v.nenri >> v.tesu;
			
			if (v.tf == 0){
				mon = tanri(money, year, v);
				// cout << "tanri " << mon << endl;
			}
			else {
				mon = fukuri(money, year, v);
				// cout << "fukuri " << mon << endl;
			}

			if (max < mon){
				max = mon;
			}

		}

		cout << max << endl;
	
	}
	



	return 0;
}

int tanri(int money, int year, ways w)
{
	int rishi;
	int i1;

	rishi = 0;

	for(i1=0;i1<year;i1++){
		rishi = rishi + money * w.nenri;
		money -= w.tesu;
	}

	return (money + rishi);

}


int fukuri(int money, int year, ways w)
{
	int rishi;
	int i1;

	for(i1=0;i1<year;i1++){
		rishi = money * w.nenri;
		money = money + rishi - w.tesu;
	}

	return money;

}