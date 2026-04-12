#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<deque>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<iomanip>
#include<sstream>
using namespace std;

#define pi acos(-1.0)
#define ms(x,n) memset(x,n,sizeof(x));

typedef long long ll;//string::npos
typedef long long iint;

ll gcd(ll a,ll b) {
	return a%b==0?b:gcd(b,a%b);
}
ll lcm(ll x,ll y) {
	ll z=gcd(x,y);
	return x*y/z;
}

const int MAXX=2e5+5;
const int INF=1e7+5;
const int mod=998244353;

vector<int> vt;
map<int,int> m1;

int main() {
	ios::sync_with_stdio(false);
	string a;
	while(cin>>a){
		int q=0,e=0;
		for(int i=0;i<3;i++){
			if(a[i]=='A'){
				q++;
			}else{
				e++;
			}
		}
		if(q&&e){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
	
	
	
	return 0;
}




//	getline(cin,a);
//	scanf("%[^\n]",a);getchar();
//	cin.getline(a,sizeof(a));