#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m;
	int smoney,year,n;
	int ht,tesu;
	int emoney;	

	double ratio;

	int max;

	cin>>m;

	for(int i1=0;i1<m;i1++){
		cin>>smoney;
		cin>>year;
		cin>>n;

		max=0;

		for(int i2=0;i2<n;i2++){
			cin>>ht>>ratio>>tesu;

			if (ht==0){
				int sum=0;
				emoney=smoney;
				for(int i3=0;i3<year;i3++){
					sum+=(emoney*ratio);
					emoney-=tesu;
				}
				emoney+=sum;
			}
			else {
				emoney=smoney;
				for(int i3=0;i3<year;i3++){
					emoney+=(emoney*ratio-tesu);
				}

			}

			if(max<emoney){
				max=emoney;
			}
		}

		cout<<max<<endl;

	}
	return 0;
}