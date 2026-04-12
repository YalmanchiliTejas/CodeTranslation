#include<iostream>
#include<algorithm>
 
using namespace std;
typedef long long Int;
#define INF (1LL<<60)

Int N;
Int res[900];

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	Int X,Y,Z;
	cin >> X>>Y>>Z;

	Int n=0;
	while (Y*n+Z*(n+1) <= X) n++;
	cout << n-1 << endl;
	return 0;
}