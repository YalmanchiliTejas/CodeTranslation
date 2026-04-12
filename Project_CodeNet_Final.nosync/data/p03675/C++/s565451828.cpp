#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iterator>
#include <set>
#include <functional>

using namespace std;

#define DT int
#define forn(i,n)for(i=0;i<n;i++)
#define forc(i,c,n)for(i=c;i<=n;i++)
#define all(x) (x).begin(), (x).end()


int main() {
	ifstream fin("Text.txt");
	int i, j, i1,j1,q;
	DT a,b,c,d,n,m,k,t,pr=0,cn=0,ans=0;
	//scanf("%I64d", &n);
	scanf("%d", &n);
	list<DT>ls;
	forn(i, n) {
		scanf("%d", &a);
		if (i & 1)
			ls.push_back(a);
		else
			ls.push_front(a);
	}
	list<DT>::iterator it;
	if (n & 1) {
		it = ls.begin();
		while (it != ls.end()) {
			cout << (*it) << " ";
			it++;
		}
	}
	else {
		ls.reverse();
		it = ls.begin();
		while (it != ls.end()) {
			cout << (*it) << " ";
			it++;
		}
	}
	return 0;
}