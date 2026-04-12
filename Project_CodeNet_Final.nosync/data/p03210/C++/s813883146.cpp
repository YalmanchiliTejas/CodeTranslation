#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>



using namespace std;

typedef unsigned long ul;
typedef pair<ul, ul> P;
#define REP(i,n) for(int i=0;i<n;i++)



int main() {

	int x;
	cin >> x;

	if (x == 3 || x == 5 || x == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;;

	return 0;

}