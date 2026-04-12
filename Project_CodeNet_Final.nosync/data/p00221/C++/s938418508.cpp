// 2012/08/08 Tazoe

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string ans[10001];

	for(int i=1; i<=10000; i++)
		if(i%15==0)
			ans[i] = "FizzBuzz";
		else if(i%3==0)
			ans[i] = "Fizz";
		else if(i%5==0)
			ans[i] = "Buzz";
		else{
			ostringstream ost;
			ost << i;
			ans[i] = ost.str();
		}

	while(true){
		int m, n;
		cin >> m >> n;

		if(m==0&&n==0)
			break;

		int ply[1000];
		for(int i=0; i<m; i++)
			ply[i] = i+1;

		for(int p=0, i=1; i<=n; i++){
			string s;
			cin >> s;

			if(m==1)		// for AOJ
				continue;

			if(s==ans[i]){
				p = (p+1)%m;
			}
			else{
				for(int j=p; j<m-1; j++)
					ply[j] = ply[j+1];
				m--;
				p = p%m;
			}
		}

		for(int i=0; i<m; i++){
			cout << ply[i];
			if(i==m-1)
				cout << endl;
			else
				cout << ' ';
		}
	}

	return 0;
}