#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
ll mcou[300];
ll n;
char s[100][100];
int main(){
	cin >> n;

	REP(i,n) {
		cin >> s[i];
	}

	REP(i,300) {
		mcou[i] = 1000000000;
	}

	REP(i,n) {
		ll cou[300];
		REP(j,300) {
			cou[j] = 0;
		}
		for(int j = 0;s[i][j] != '\0';j++) {
			cou[s[i][j]]++;
		}

		for(int j = 'a';j <= 'z';j++) {
			mcou[j] = min(mcou[j],cou[j]);
		}
	}

	for(int i = 'a';i <= 'z';i++) {
		REP(j,mcou[i]) {
			char c = i;
			cout << c;
		}
	}
	cout << endl;
	return 0;
}
