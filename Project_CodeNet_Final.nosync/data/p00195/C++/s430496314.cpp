#include <iostream>
using namespace std;

int main() {
	int i,a,b,c,s,k;
	while(true) {
		for (i=s=c=0;i<5;i++) {
			cin >> a >> b; k=a+b; if (k==0) break;
			if (k>s) { s=k; c=i;}
		}
		if (k==0) break;
		cout << (char)('A'+c) <<  ' ' <<  s << endl;
	}
	return 0;
}