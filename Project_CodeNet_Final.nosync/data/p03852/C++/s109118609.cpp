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

//おまじない



int main() {

	char a;
	cin >> a;
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}

	return 0;
}