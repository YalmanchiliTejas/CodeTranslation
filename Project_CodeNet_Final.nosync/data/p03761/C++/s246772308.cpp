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
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
int N;
vector <string > S;
int num['z' - 'a'+1] = {};




int main()
{

	cin >> N;

	S.resize(N);

	REP(i,N){
		cin >> S[i];
	}

	REP(i,S[0].size()){
		num[S[0][i] - 'a']++;
	}

	FOR(i,1,N){
		int num1['z' - 'a'+1] = {};
		REP(j,S[i].size()){
			num1[S[i][j]-'a']++;
		}
		REP(i,'z'-'a'+1){
			if(num[i]==0)
				continue;
			if(num[i] > num1[i])
				num[i] = num1[i];
		}
	}

	int ans =0;
	REP(i,'z'-'a'+1){
		REP(j,num[i]){
			printf("%c",'a'+i);
		}
	}


}
