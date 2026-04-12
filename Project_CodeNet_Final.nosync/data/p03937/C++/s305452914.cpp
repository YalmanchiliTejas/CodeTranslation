/*input
5 3
###
..#
###
#..
###
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100
#define INF 0x3f3f3f3f

int n , m;
string s[MAX];
int cmp(PII x , PII y){ return x.A + x.B < y.A + y.B; }
int32_t main(){
	IOS;
	cin >> n >> m;
	vector<PII> v;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] == '#') v.pb(i , j);
	sort(ALL(v) , cmp);
	REP(i , 1 , v.size()) if(v[i].A + v[i].B != v[i - 1].A + v[i - 1].B + 1)
		return cout << "Impossible" << endl , 0;
	REP(i , 1 , v.size()){
		int xx = v[i].A - v[i - 1].A;
		int yy = v[i].B - v[i - 1].B;
		if(xx == 1 && yy == 0 || xx == 0 && yy == 1);
		else return cout << "Impossible" << endl , 0;
	}
	cout << "Possible" << endl;
    return 0;
}