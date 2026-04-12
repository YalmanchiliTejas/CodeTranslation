#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(i=a;i<b;i++)
#define rloop(i,a,b) for(i=a;i>=b;i--)
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
const int inf=1000000001;
const ll INF=1e16;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846

int main(){
	int n,i,j;
	cin>>n;
	vs s(n);
	int m=inf,mi;
	loop(i,0,n){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		m=min(m,(int)s[i].size());
		if(m==s[i].size()){
			mi=i;
		}
	}
	vector<char> ans;
	i=0;
	while(i<s[mi].size()){
		m=count(s[mi].begin(),s[mi].end(),s[mi][i]);
		i+=m;
		loop(j,0,s.size()){
			m=min(m,(int)count(s[j].begin(),s[j].end(),s[mi][i-m]));
		}
		loop(j,0,m){
			ans.push_back(s[mi][i-m]);
		}
	}
	loop(i,0,ans.size()){
		cout<<ans[i];
	}
	cout<<endl;
}