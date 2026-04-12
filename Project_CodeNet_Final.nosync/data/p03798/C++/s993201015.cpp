#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <functional>

using namespace std;
typedef long long ll;
#define pl pair<ll,ll>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); itr++)
#define dbg(x) cout << #x"="<< (x) << endl
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a) 
#define in(x) cin >> x;
#define all(x) (x).begin(), (x).end()
#define INF 2147483600
#define fi first
#define se second

ll N;
string s;
vector<bool> solve(bool a, bool b){
	vector<bool> res(N+2);
	res[0] = a;
	res[1] = b;
	FOR(i,1,N+1){
		if(s[i]=='o'){
			res[i+1]=(res[i]==true)?res[i-1]:!res[i-1];
		}else{
			res[i+1]=(res[i]==true)?!res[i-1]:res[i-1];
		}
	}
	return res;
}

//判定をする
//始めの条件から得られる値と最後の値が等しいのか
bool judge(vector<bool> c){
	bool temp= (c[0]==true)?c[1]:!c[1];
	bool top;
	if(s[0]=='o'){
		top=(c[N-1]==temp);
	}else{	
		top=(c[N-1]==!temp);
	}
	return (top&&(c[N]==c[0]));
}

int main(){
	cin>>N;
	cin>>s;
	string ans ="-1";
	vector<bool> sig;
	bool flag=true;
	//始めと隣が決まれば全部決まる.
	int dx[4]={0,1,0,1},dy[4]={0,0,1,1};
	rep(i,4){
		sig=solve(dx[i],dy[i]);
		if(judge(sig)){
			ans="";
			rep(i,N){
				if(sig[i]){
					ans+='S';
				}else{
					ans+='W';
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}










