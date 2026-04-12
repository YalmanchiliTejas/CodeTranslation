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

	int r, g, b; cin >> r >> g >> b;

	int n = r*100+g*10+b;
	
	if(n%4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;

}
