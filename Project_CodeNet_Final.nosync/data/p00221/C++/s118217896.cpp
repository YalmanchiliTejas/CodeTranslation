// 2011/07/15 Tazoe

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string ans[10000];

	for(int i=0; i<10000; i++)
		if((i+1)%15==0)
			ans[i] = "FizzBuzz";
		else if((i+1)%3==0)
			ans[i] = "Fizz";
		else if((i+1)%5==0)
			ans[i] = "Buzz";
		else{
			ostringstream ost;
			ost << i+1;
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

		int p = 0;
		for(int i=0; i<n; i++){
			string s;
			cin >> s;

			if(m==1)
				continue;

			if(s==ans[i])
				p = (p+1)%m;
			else{
				for(int j=p; j<m-1; j++)
					ply[j] = ply[j+1];
				m--;
				if(p==m)
					p = 0;
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