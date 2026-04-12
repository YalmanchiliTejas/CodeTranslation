#include <iostream>
#include <string>
#define foor for(int i=0;i<n;i++)
#define en endl;
#define el else
#define co cout
#define in int
int s = 0;
using namespace std;
int main() {
	int n = 3;
	char a;
	foor{
		cin >> a;
	if (a == 'A') {
		s++;
	}
	}
	if (s!=0&&s!=3)co << "Yes"<<en
		el co<<"No"<<en
}