#include<bits/stdc++.h>
 
#define REP(i,s,n) for(int (i)=s; (i)<(int)(n);(i)++)
#define RIT(it,c) for(__typeof(c.begin()) it = c.begin();it!=c.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x).size()
#define MSET(m,v) memset(m,v,sizeof(m))
 
 
using namespace std;
 
 
typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<LL> vL;
typedef vector<bool> vb;
typedef pair<int,vi> iv;
typedef pair<LL,LL> pLL; 
typedef long double LD;
typedef unordered_set<int> ui;



int main(){
	std::ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	if(s.find("AC") != string::npos) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
