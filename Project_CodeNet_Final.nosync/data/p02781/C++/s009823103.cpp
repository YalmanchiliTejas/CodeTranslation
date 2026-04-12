#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define mod 1000000007
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int op2(string s){
	int ans=0;
	if(s.size()<2)
		return 0;
	ans+=(((s.size()-1)*(s.size()-2))/2)*81;
	ans+=((s[0]-'0'-1)*(s.size()-1))*9;
	int j=1;
	if(s[j]!='0'){
		ans+=s[j]-'0';
		ans+=(s.size()-2)*9;
	}
	else{
		while(j<s.size()&&s[j]=='0')
			j++;
		if(j!=s.size()){
			ans+=s[j]-'0';
			ans+=(s.size()-1-j)*9;
		}
	}
	return ans;
}


int main() {
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		string s;
		cin>>s;
		int k;
		cin>>k;
		if(s.size()<k){
			cout<<0;
			return 0;
		}
		if(k==1){
			ll ha=9*(s.size()-1);
			ha+=s[0]-'0';
			cout<<ha;
			return 0;
		}
		if(k==2){
			cout<<op2(s);
		}
		else{
			int ans=0;
			ans+=(((s.size()-1)*(s.size()-2)*(s.size()-3))/6)*9*9*9;
			string q=s;
			q.erase(q.begin());
			ans+=(s[0]-'0'-1)*(((s.size()-1)*(s.size()-2))/2)*9*9;
			s.erase(s.begin());
			
			while(s.size()!=0&&s[0]=='0')
				s.erase(s.begin());
			ans+=op2(s);
			cout<<ans;
		}

	}
	return 0;
}