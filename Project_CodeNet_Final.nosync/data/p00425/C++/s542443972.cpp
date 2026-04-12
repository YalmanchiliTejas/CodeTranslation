#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>


using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int nowp[3];
int main(){
	vector<int> ans;
	while(1){
		int n;
		cin>>n;
		if(n==0)break;
		nowp[0]=1;
		nowp[1]=2;
		nowp[2]=3;
		int tans=1;
		REP(i,n){
			string s;
			int temp[3];
			cin>>s;
			if(s=="North"){
				temp[0]=nowp[1];
				temp[1]=7-nowp[0];
				temp[2]=nowp[2];
			}else if(s=="East"){
				temp[0]=7-nowp[2];
				temp[1]=nowp[1];
				temp[2]=nowp[0];
			}else if(s=="West"){
				temp[0]=nowp[2];
				temp[1]=nowp[1];
				temp[2]=7-nowp[0];
			}else if(s=="South"){
				temp[0]=7-nowp[1];
				temp[1]=nowp[0];
				temp[2]=nowp[2];
			}else if(s=="Right"){
				temp[0]=nowp[0];
				temp[1]=nowp[2];
				temp[2]=7-nowp[1];
			}else if(s=="Left"){
				temp[0]=nowp[0];
				temp[1]=7-nowp[2];
				temp[2]=nowp[1];
			}
			REP(j,3)nowp[j]=temp[j];
			tans+=nowp[0];
		}
		ans.push_back(tans);
	}
	REP(i,ans.size())cout<<ans[i]<<endl;
	return 0;
}