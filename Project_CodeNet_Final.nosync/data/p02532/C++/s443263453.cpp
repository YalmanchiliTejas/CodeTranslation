#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
	string		odr;
	stack<char>	*clr;
	char		chr;
	int		n,p1,p2;

	cin >> n;
	clr = new stack<char>[n];

	do{
		cin >> odr;
		if(odr=="push"){
			cin >> p1;
			cin >> chr;
			clr[p1-1].push(chr);
		}
		else if(odr=="pop"){
			cin >> p1;
			chr = clr[p1-1].top();
			clr[p1-1].pop();
			cout << chr << endl;
		}
		else if(odr=="move"){
			cin >> p1;
			cin >> p2;
			chr = clr[p1-1].top();
			clr[p1-1].pop();
			clr[p2-1].push(chr);
		}
	}while(odr!="quit");

	return 0;
}