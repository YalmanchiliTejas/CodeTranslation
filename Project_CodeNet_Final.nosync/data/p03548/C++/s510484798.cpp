// B - ISU
#include <bits/stdc++.h>
using namespace std;

int main(){
	int X,Y,Z; cin>>X>>Y>>Z;
	int ans = X/(Y+Z);
	cout<< (ans*(Y+Z)+Z > X? ans-1: ans) <<endl;
}