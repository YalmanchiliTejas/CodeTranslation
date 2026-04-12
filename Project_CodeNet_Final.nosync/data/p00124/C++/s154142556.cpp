#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

int main() {
    int a,b,c,n,f=0;
	string st;
	map<int,string> mp;
	map<int,string>::reverse_iterator it;
	while (cin >> n) {
		if (n==0) break;
		for (n--;n>=0;n--) {
			cin >> st >> a >> b >> c;
			mp.insert(map<int,string>::value_type((a*3+c)*10+n,st));
		}
    if (f==0) f=1; else cout << endl;
	for (it=mp.rbegin();it!=mp.rend();it++) cout << (*it).second << ',' << (*it).first/10 << endl;
	mp.clear();
	}
    return 0;
}