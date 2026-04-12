#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
int H,W;
vector <string > A;



int main()
{

	cin >> H >> W;

	A.resize(H);
	REP(i,H){
		cin >> A[i];
	}

	REP(i,H-1){
		REP(j,W-1){
			if(A[i+1][j] == '#' && A[i][j+1] == '#') {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
}