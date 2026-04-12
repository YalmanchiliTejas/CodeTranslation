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
	string S; cin >> S;
	int K; cin >> K;

	char c = S[K-1];
	REP(i,N){
		if(c != S[i]) S[i] = '*';
	}

	cout << S << endl;


	return 0;

}
