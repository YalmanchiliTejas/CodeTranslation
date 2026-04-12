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

	int N; cin >> N;
	vector<int> H(N);

	REP(i,N) cin >> H[i];


	int ans = 0;
	int maxnum = -1;
	// FOR(i,1,N+1){
	REP(i,N){
		if(H[i] >= maxnum){
			ans++;
			maxnum = H[i];
		}
	}
		
	cout << ans << endl;


	return 0;

}
