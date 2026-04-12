#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solver
{
public:
	long n;
	long m;


	Solver() {
		cin >> n;
		cin >> m;
	}

	void exec() {
		if(n == m ) {
			cout << "Yes" << endl;
		} else {
			cout << "No"  << endl;
		}
	}
};
int main(){
	Solver co = Solver();
	co.exec(); 
}
