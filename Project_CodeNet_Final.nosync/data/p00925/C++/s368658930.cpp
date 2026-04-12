#include <bits/stdc++.h>
using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

const int INF=1e9;
const int MOD=1e9+7;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

tuple<ll,int> term(const string& s,int i)
{
	ll x=s[i++]-'0';
	while(i<s.size() && s[i]=='*'){
		i++;
		x*=s[i++]-'0';
	}
	return mt(x,i);
}
ll expr(const string& s)
{
	ll x; int i;
	tie(x,i)=term(s,0);
	while(i<s.size() && s[i]=='+'){
		i++;
		ll y; tie(y,i)=term(s,i);
		x+=y;
	}
	return x;
}

ll calc(const string& s)
{
	stack<ll> st;
	char op;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			st.push(s[i]-'0');
			if(st.size()==2){
				ll b=st.top(); st.pop();
				ll a=st.top(); st.pop();
				st.push(op=='+'?a+b:a*b);
			}
		}
		else
			op=s[i];
	}
	return st.top();
}

int main()
{
	for(string s;cin>>s && s!="#";){
		ll ans; cin>>ans;
		
		ll infix=expr(s);
		ll left=calc(s);
		
		if(infix==ans && left==ans)
			cout<<'U'<<endl;
		else if(infix==ans)
			cout<<'M'<<endl;
		else if(left==ans)
			cout<<'L'<<endl;
		else
			cout<<'I'<<endl;
	}
}