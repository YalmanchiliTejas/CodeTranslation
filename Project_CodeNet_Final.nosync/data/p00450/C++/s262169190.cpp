#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int sign(int a){
	return (a>0?1:-1);
}
int main() {
	int n;
	while(cin>>n,n){
		vi stones;
		REP(i,n){
			int c;
			cin>>c;
			if(stones.size()==0){
				stones.push_back(c>0?1:-1);
			}else{
				vi::iterator back=stones.end()-1;
				if(*back>0==c){
					(*back)+=sign(*back)*1;
				}else{
					if(i%2==0){
						stones.push_back(c>0?1:-1);
					}else{
						if(stones.size()==1){
							(*back)*=-1;
							(*back)+=sign(*back)*1;
						}else{
							int a=abs(*back);
							stones.erase(back);
							vi::iterator newback=stones.end()-1;
							*newback+=sign(*newback)*a;
							*newback+=sign(*newback)*1;
						}
					}
				}
			}
		}
		int ans=0;
		REP(i,stones.size()){
			ans+=stones[i]<0?-stones[i]:0;
		}
		cout<<ans<<endl;
	}
}