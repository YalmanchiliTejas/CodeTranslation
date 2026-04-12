#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
	int n;
	cin >> n;
	cout << 800 * n - 200 * (n/15) << endl;
}