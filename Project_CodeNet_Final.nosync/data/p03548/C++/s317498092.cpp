#include <bits/stdc++.h>
using namespace std;

int X,Y,Z,sum;

int main(){
	cin>>X>>Y>>Z;
	sum = X - Z;
	cout<< sum / (Y + Z) <<endl;
}
