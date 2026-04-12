#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double pi = 3.141592653589793;
ll mod = 1000000007;
ll INF = 1000000001;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;



int main(){
	int n;cin>>n;
	vi v(n);
	
	int cnt=0;
	rep(i,n){
		cin>>v[i];
	}
	int m=0;
	rep(i,n){
		m = max(m,v[i]);
		if(m==v[i]){
			cnt+=1;
		}
	}
	cout<<cnt<<endl;
    return 0;
}