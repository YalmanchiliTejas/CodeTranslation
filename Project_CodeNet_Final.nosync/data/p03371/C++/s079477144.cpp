#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
	cout<<min(A*X+B*Y,min(2*C*max(X,Y),A*(X-min(X,Y))+B*(Y-min(X,Y))+2*C*min(X,Y)));
}