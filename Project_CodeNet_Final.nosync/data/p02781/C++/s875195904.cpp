// Author : Sarthak Kapoor
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define msi map<string,int>
#define mii map<int,int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define po pop_back
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
 //    	freopen("input.txt", "r", stdin);
 //    	freopen("output.txt", "w", stdout);
	// #endif
	string s;
	cin>>s;
	int k;
	cin>>k;
	int num = s(s);
	int i = 1;
	ll ans = 0;
	ll c[num+1][3];
	if(num < k){
		cout<<0;
		return 0;
	}
	rep(i,num+1){
		c[i][0] = 1;
		c[i][1] = i;
		c[i][2] = i*(i-1)/2;
	}
	while(i < num){
		if(i < k){i++;continue;}
		ll temp = 0;
		temp += c[i-1][k-1];
		rep(j,k){
			temp *= 9;
		}
		ans += temp;
		i++;
	}	
	if(k == 3){
		int f = 0;
		repa(i,1,num){	
			int f2 = 0;
			repa(j,i+1,num){
				ans += (s[0] - '1')*9*9;
				if(s[i]!='0' && f == 0)ans += (s[i] - '1')*9;
				else if(f == 0);
				else {
					ans += 9*9;
					// if(s[i]!='0')f++;
					if(s[j]!='0')f2++;
					// cout<<i<<" "<<j<<" "<<ans<<"\n";
					continue;
				}
				if(s[i] == '0' && f == 0);
				else if(s[j] == '0' && f+f2==0);
				else if(f + f2 > 0)ans += 9;
				else ans += s[j]-'0';
				
				if(s[j]!='0')f2++;
				// cout<<i<<" "<<j<<" "<<ans<<"\n";
			}
			if(s[i]!='0')f++;
		}
	}
	else if(k == 2){
		int f = 0;
		repa(i,1,num){
			ans += (s[0] - '1')*9;
			if(f == 0){ans += (s[i]-'0');}
			else ans += 9;
			if(s[i]!='0')f++;
		}
	}
	else{
		ans += (s[0]-'0');
	}
	cout<<ans;
	return 0;
}