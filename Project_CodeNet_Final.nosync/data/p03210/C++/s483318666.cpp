#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int X;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> X;
	if(X == 3 || X == 5 || X == 7){
      cout << "YES" << endl;
    }else{
   		cout << "NO" << endl;  
    }
	return 0;
}