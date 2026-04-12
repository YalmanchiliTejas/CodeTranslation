#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b) - 1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

#define PB push_back
#define INF INT_MAX/3
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CLR(a) memset(a,0,sizeof(a))

typedef long long int ll;

using namespace std;

int main(){
    while(true){
	vector< pair<int,string> > sh(5);
	int s1,s2;
	string a[] = { "A" , "B" , "C" , "D" , "E"};
	REP(i,5){
	    cin >> s1 >> s2;
	    if(s1 == 0 && s2 == 0) break;
	    sh.PB( pair<int,string>(s1+s2, a[i] ));
	}
	if(s1 == 0 && s2 == 0) break;
	sort(RALL(sh));
	cout << sh[0].second << " " << sh[0].first << endl;
    }
    return 0;
}