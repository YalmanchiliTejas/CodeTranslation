//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <fstream>
#include <complex>
#include <math.h>

using namespace std;

//conversion
//------------------------------------------
inline long toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline long toLong(string s) {long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(long i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

//constant
//--------------------------------------------

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const long double EPS = 1e-8;
const long INF = 1e10;

int main(){
	long N;string str;
	cin>>str>>N;
	int bpos=0;
	vector<int>num;
	vector<char>kigo;
	REP(i,SZ(str)){
		if(str[i]=='+'||str[i]=='*'){
			kigo.PB(str[i]);
			num.PB(toInt(str.substr(bpos,i-bpos+1)));
			bpos=i+1;
		}else if(i==SZ(str)-1){
			num.PB(toInt(str.substr(bpos)));
		}
	}
	long L=num[0];
	FOR(i,1,SZ(num)){
		if(kigo[i-1]=='+')L+=num[i];
		else L*=num[i];
	}
	stack<long>st;
	st.push(num[0]);
	FOR(i,1,SZ(num)){
		if(kigo[i-1]=='+')st.push(num[i]);
		else{
			long t=st.top();st.pop();
			st.push(t*num[i]);
		}
	}
	long M=0;
	while(!st.empty()){
		M+=st.top();st.pop();
	}
	//cout<<L<<" "<<M<<endl;
	if(N==L&&N==M){
		cout<<"U"<<endl;
	}else if(N==L){
		cout<<"L"<<endl;
	}else if(N==M){
		cout<<"M"<<endl;
	}else{
		cout<<"I"<<endl;
	}
	return 0;
}