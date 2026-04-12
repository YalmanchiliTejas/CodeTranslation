#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>

using namespace std;


int main() {
	map<int, int> mp;
	long long int n, m=0,tmp=0,ax=0,k=0,t[500000],p[500000],x,y,res[5000],a,b,c;
	string str, str2[5000];
	cin >>n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		p[i] = t[i];
	}
	sort(t + 1, t + n + 1);

	for (int i = 1; i <= n; i++) {
		if (p[i] < t[n / 2 + 1]) {
			cout << t[n / 2 + 1] << endl;
		}
		else {
			cout << t[n / 2 ] << endl;
		}
	}
}