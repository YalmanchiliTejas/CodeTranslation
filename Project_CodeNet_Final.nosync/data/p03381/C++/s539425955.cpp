#include <vector>
#include <list>
#include <map>
#include <queue>
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

#define REP(i,n)for (int i=0;i<(n);i++)
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ll long long
using namespace std;
typedef pair<char,char> P;

int main(){
	int n;
	cin>>n;
	vector<int>x(n),v(n);
	REP(i,n)cin>>v[i];
	x=v;
	sort(ALL(v));
	int ans1=v[n/2-1];
	int ans2=v[n/2];
	REP(i,n){
		if(x[i]<=ans1){
			cout<<ans2<<endl;
		}else{
			cout<<ans1<<endl;
		}
	}
}
