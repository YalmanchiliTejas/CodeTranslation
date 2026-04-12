#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((100*a + 10*b + c)%4 == 0 ? "YES" : "NO") << endl;
}