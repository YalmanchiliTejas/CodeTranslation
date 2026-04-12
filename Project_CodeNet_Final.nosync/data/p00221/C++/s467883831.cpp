#include<iostream>
#include<bitset>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
using namespace std;

string get_str(const int& n) {
	ostringstream buff;
	if(n % 3 != 0 && n % 5 != 0) {
		buff << n;
	}
	else {
		if(n % 3 == 0) {
			buff << "Fizz";
		}
		if(n % 5 == 0) {
			buff << "Buzz";
		}
	}
	return buff.str();
}

int main() {
	bool mem[1000];
	string buff;
	int m, n, ite, bf;

	while(cin >> m >> n) {
		if(m == 0 && n == 0) break;
		
		for(int i = 0; i < m; ++i) { mem[i] = true; }
		ite = 0;
		bf = 1;
		for(int i = 1; i <= n; ++i){
			cin >> buff;
			buff != get_str(i) && ite != bf ? mem[ite] = false : bf = ite;

			while(++ite < m ? !mem[ite] : !mem[ite = 0]);
		}
		ite = 0;
		while(!mem[ite]) { ++ite; }
		while(1) {
			cout << ite + 1;
			while(!mem[++ite]);
			if( !(ite < m) ) { break; }
			cout << " ";
		}
		cout << endl;
	}


}