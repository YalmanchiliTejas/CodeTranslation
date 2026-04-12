#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back
#define pp pop_back
#define pii pair<int,int>
#define fi first
#define se second 
#define in insert
#define er erase
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int mx=1e5+10;
int a[mx];
int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	for(int i=0;i<4;i++){
		a[0]=i/2,a[1]=i%2;
		for(int j=2;j<n;j++){
			int t=(s[j-1]=='x');
			a[j]=a[j-1]^t^a[j-2];
		}
//		for(int j=0;j<n;j++) cout<<a[j]<<" ";
//		cout<<endl;
		int t0=(s[0]=='x'),tn=(s[n-1]=='x');
		if((a[1]^t0^a[0])==a[n-1] && (a[n-1]^a[n-2]^tn)==a[0]){
			for(int i=0;i<n;i++) cout<<(a[i]?'W':'S');
			return 0;
		}
	}
	cout<<-1;
}
