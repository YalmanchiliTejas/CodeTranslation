#include<iostream>
#include<cmath>
#include<algorithm>
#include <cassert>
#include<string>
#include<vector>
#include <utility>
#include <math.h>
using namespace std;
int a = 0, b = 0, c = 0, d = 0, e[1050] = {}, f[100010] , counto = 0, counto1 = 1145148;
double syo = 0, su = 0;
char mado[105][105];
bool mazi[110], gi[110];
pair<int, int>n[110];
vector<int> r;
int main() 
{
	cin >> a >> b ;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> mado[i][j];
			if (mado[i][j] == '#') {
				mazi[i] = true;
				gi[j] = true;
			}
		}
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (mazi[i] == true && gi[j] == true) {
				cout << mado[i][j];
				counto++;
			}
		}
		if (counto != 0) {
			cout << endl;
		}
		counto = 0;
	}
	return 0;
}