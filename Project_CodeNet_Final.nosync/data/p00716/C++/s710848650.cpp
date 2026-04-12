#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
	int m=0,n=0;
	int money=0;
	int year=0;
	int r=0;
	double rate=0;
	int tax=0;
	int risi=0;
	int ans=0;
	vector<int> anss;

	cin >> m;

	for(int i=0;i<m;i++){
		cin >> money;
		cin >> year;
		cin >> n;
		
		for(int j=0;j<n;j++){
			cin >> r >> rate >> tax;

			ans=money;

			if(r==0){
				for(int k=0;k<year;k++){
					risi = risi + floor(double(ans)*rate);
					ans = ans - tax;
				}
				ans = ans + risi;
			}else{
				for(int k=0;k<year;k++){
					ans = ans + floor(double(ans)*rate) - tax;
				}
			}
			anss.push_back(ans);
			risi=0;
			ans=0;
			tax=0;
		}
		sort(anss.begin(),anss.end());
		cout << anss.back() << endl;
		risi=0;
		ans=0;
		tax=0;
		anss.clear();
	}
}