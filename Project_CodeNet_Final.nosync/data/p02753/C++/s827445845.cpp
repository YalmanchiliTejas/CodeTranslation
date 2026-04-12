 #include "bits/stdc++.h"

using namespace std;

#define sp(x) cout<<setprecision(x);
#define all(a) (a).begin(), (a).end()
#define inf 10000000
#define linf INT64_MAX*0.99
#define lint long long
#define FOR(i,a,b) for(lint i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define yes "Yes"
#define no "No"
#define divs 1000000007
#define dive 1000000009

typedef pair<int, int> P;

lint ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	string s; cin>>s;
	if(s[0]==s[1]&&s[1]==s[2]&&s[0]==s[2]) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
    return 0;
}