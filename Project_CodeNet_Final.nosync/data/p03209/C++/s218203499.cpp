#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
int a(int n){
	if(n==0)return 1;
	else return 2*a(n-1)+3;
}
int p(int n){
	if(n==0)return 1;
	else return 2*p(n-1)+1;
}

int f(int n,int x){
	if(n==0) return 1;
	else if(x==1)return 0;
	else if(2<=x&&x<=a(n-1)+1) return f(n-1,x-1);
	else if(x==a(n-1)+2) return p(n-1)+1;
	else if(a(n-1)+3<=x&&x<=2*a(n-1)+2)  return p(n-1)+1+f(n-1,x-a(n-1)-2);
	else if(x==2*a(n-1)+3)return 2*p(n-1)+1;
}

signed main(){
	int n,x;
	cin>>n>>x;
	cout<<f(n,x)<<endl;

	// string s="P";
	// rep(i,n){
	// 	s='B'+s+'P'+s+'B';
	// }
	// cout<<s<<endl;
	// int cnt=0;
	// rep(i,x){
	// 	cnt+=s[i]=='P';
	// }		
	// cout<<cnt<<endl;

	return 0;
}
