#include <iostream>
#include <cmath>

using namespace std;
long burger(long N, long X);

int main(void){
	long n, x;
	cin >> n >> x;
	cout << burger(n, x) << endl;
	return 0;
}

long burger(long N, long X){
	if(N == 0){
		return X;
	}
	else{
		if(X == 1)	return 0;
		else if(X <= 1 + pow(2,N+1)-3)	return burger(N-1,X-1);
		else if(X == 2 + pow(2,N+1)-3)	return burger(N-1,pow(2,N+1)-3)+1;
		else if(X <= 2 + 2*(pow(2,N+1)-3))	return	burger(N-1,pow(2,N+1)-3)+1+burger(N-1,X-2-(pow(2,N+1)-3));
		else if(X == 3 + 2*(pow(2,N+1)-3))	return 1+2*burger(N-1,pow(2,N+1)-3);
	}
	return -1;
}
