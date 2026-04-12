#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define LL long long;
#define ULL unsigned long long;
using namespace std;

char c;

int main() {
	cin>>c;
	cout<<(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'?"vowel":"consonant")<<endl;
}
