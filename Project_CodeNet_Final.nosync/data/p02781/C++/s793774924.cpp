#include <bits/stdc++.h>
#define rep(i,n1) for(int i=0;i<n1;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<'YES'<<endl;}else{cout<<'NO'<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
#define PI 3.141592653589793
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<int,ll> Pil;
typedef pair<ll,ll> Pll;
typedef pair<string,int> Psi;
typedef pair<Psi,int> Psii;

const ll inf=1000000007;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

vector<Pii> v[100001];
ll dp2[300000][60]={};
ll calc(ll n1,int k1){
	if(n1<k1||k1==0)return 0;
	if(k1==1)return 9*n1;
	if(k1==2)return (9*9*(n1-1)*n1)/2;
	if(k1==3)return (9*9*9*n1*(n1-1)*(n1-2))/6;
}
int main() {
	string s;
	int k;
	cin>>s>>k;
	int n=s.size();
	ll r=0;
	int p=0;
	while(k>0&&p<n){
		int i=(int)s[p]-48;
		if(i>0){
			r+=calc(n-p-1,k);//0
			r+=(i-1)*calc(n-p-1,k-1);
			if(k==1)r+=i;
			k--;
		}
		p++;
	}
	cout<<r<<endl;
	return 0;
}
