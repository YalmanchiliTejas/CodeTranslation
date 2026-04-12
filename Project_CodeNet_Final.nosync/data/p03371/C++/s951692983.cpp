#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;
	int planA=0;
	int planB=0;
	int planC=0;

	planA = A*X+B*Y;

	int hoge=min(X,Y);
	planB = hoge*C*2 + A*(X-hoge) + B*(Y-hoge);

	int piyo=max(X,Y);
	planC = piyo*C*2;

	int tako=min(planA,min(planB,planC));
	cout << tako << endl;


	return 0;
}
