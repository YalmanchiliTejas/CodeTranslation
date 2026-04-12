//============================================================================
// Name        : JOI.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int X,Y,Z;
int main() {
	cin>>X>>Y>>Z;
	int A,B;
	A=Z;
	for(int i=1;;i++){
		A+=Y+Z;
		if(A<=X)B=i;
		else break;
	}

	cout<<B<<endl;
	return 0;
}
