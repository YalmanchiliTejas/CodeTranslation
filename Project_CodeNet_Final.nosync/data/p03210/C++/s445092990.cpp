#include <stdio.h>
#include <cmath>
#include <bits/stdc++.h>



using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;


//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)



int main(void){

	
	int X; cin >> X;

	if(X == 7 or X == 5 or X == 3) cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;

}
