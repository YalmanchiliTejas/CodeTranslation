//おまじない
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 1e9+7
#define roop(i,m,n) for(int i=m;i<n;i++)
#define mroop(i,m,n) for(int i=m;i<n;i--)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
using namespace std;
typedef long long int ll;

//(int)'a'は97 (int)'A'は65
//おまじない



int main() {
	
	int x, y,z;
	cin >> x >> y>>z;

	if ((x * 100 + y * 10 + z) % 4 == 0) {
		YES;
	}
	else {
		NO;
	}


	return 0;
}
