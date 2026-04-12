// C - Half and Half
#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
	int n = A+B > C*2? min(X, Y): 0;
	cout<< C*2*n + min(A, C*2)*(X-n) + min(B, C*2)*(Y-n) <<endl;
}