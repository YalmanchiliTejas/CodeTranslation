#include <iostream>
#include <sstream>
using namespace std;

string fizzbuzz(int i)
{
	stringstream sst;
	sst << i;
	if(i%15==0)
		return "FizzBuzz";
	else if(i%5==0)
		return "Buzz";
	else if(i%3==0)
		return "Fizz";
	else
		return sst.str();
}

int main()
{
	int m,n;
	while(cin >> m >> n){
		if(m == 0 && n == 0)
			break;
		string str;
		bool *player = new bool[m];
		int check = m;
		for(int i=0;i<m;i++){
			player[i] = true;
		}

		int pos = 0;
		for(int i=0;i<n;i++){
			cin >> str;
			if(check != 1 && str != fizzbuzz(i+1)){
				player[pos] = false;
				check--;
			}
			pos++;
			pos%=m;
			if(check != 1){
				while(player[pos] != true){pos++;pos%=m;}
			}
		}

		bool flag = false;
		for(int i=0;i<m;i++){
			if(player[i] == true){
				if(flag == true)
					cout << " ";
				cout << i+1;
				flag = true;
			}
		}
		cout << endl;
		delete[] player;
	}
	return 0;
}