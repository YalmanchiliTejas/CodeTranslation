#include<bits/stdc++.h>
#define int(x) int x; scanf("%d",&x);
#define lnt(x) long long x; scanf("%lld",&x);
#define dbl(x) double x; scanf("%lf",&x);
#define str(x) string x; cin >> x;
#define fo(i,a,b) for (int i=(a);i<(b);i++)
#define rf(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rp(i,n) for (int i=0;i<(n);i++)
#define rrp(i,n) for (int i=(n)-1;i>=0;i--)
#define inf INT_MAX/3
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pcc pair<char,char>
#define pci pair<char,int>
#define vs vector<string>
#define vi vector<int>
#define ll long long
#define in(x) cin>>x;
#define ot(x) cout<<x;
#define eot(x) cout<<x<<endl;
#define sot(x) cout<<x<<" ";
using namespace std;
int main(){
	string s1="yuiophjklnm";
	while(1){
		str(s)	
		if(s=="#")break;
		int c[33]={},ans=0;
		rp(i,s.size()){
			rp(j,s1.size()){
				if(s[i]==s1[j]){
					c[i]=1;
					break;
				}
			}
		}
		fo(i,1,s.size()){
			if((c[i]-c[i-1])!=0){
				ans++;
			}
		}
		eot(ans)
	}
	return 0;
}