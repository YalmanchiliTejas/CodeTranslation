#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int money,year,n;
		int max = 0;
		cin >> money >> year >> n;
		for(int j=0;j<n;j++){
			bool flag;
			double nennri;
			int risi;
			cin >> flag >> nennri >> risi;
			int mon = money;
			if(flag)
				for(int k=0;k<year;k++)
					mon = mon+static_cast<int>(static_cast<double>(mon)*nennri)-risi;
			else{
				int B=0;
				for(int k=0;k<year;k++){
					B +=  static_cast<int>(static_cast<double>(mon)*nennri);
					mon -= risi;
				}
				mon += B;
			}
			if(max < mon)
				max = mon;
		}
		cout << max << endl;
	}
	return 0;
}