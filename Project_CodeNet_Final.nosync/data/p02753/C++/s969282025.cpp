// garnab27
#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define ll int64_t
#define F first
#define S second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
ll modex(ll a,ll b,ll p){ll res=1;a%=p;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b>>=1;}return res;}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);	
 
	string s;
	cin>>s;

	int a=0, b=0;
	for(char c:s) {
		if(c=='A') a++;
		else b++;
	}

	if(a==3 || b==3) cout<<"No";
	else cout<<"Yes";
 
 
	return 0;
}