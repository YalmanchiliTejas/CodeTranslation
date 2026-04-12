// C - Half and Half
#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
	cout<< ( A+B<=C*2? A*X + B*Y:
		C*2 * min(X, Y) + min((X>Y? A:B), C*2) * abs(X-Y) ) <<endl;
}