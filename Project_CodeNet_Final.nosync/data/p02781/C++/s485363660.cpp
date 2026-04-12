#include<bits/stdc++.h>
#define FOR(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define FORN(i,b,a)for(int i=(b);_a=(a);i>=_a;i--)
#define REP(i,n)for(int i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define re return
#define vi vector<int>
#define pb push_back
#define si set<int>
#define in insert
#define fl float
#define db double
#define ld long double
#define X first
#define Y second
#define st string
using namespace std;
inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
int main(){
	string n;
	cin>>n;
	int k;
	ll c=0;
	cin>>k;
	ll ans=0;
	ll t;
	t = n.size();
	if (k == 1){
		cout<<(t-1)*9+n[0]-'0'<<endl;
	}
	else if(k==2){
		if (t<2){
			cout<<0<<endl;
			return 0;
		}
		ans+=(t-1)*(t-2)/2*(ll)(9*9);
		ans+=max((ll)0,(ll)(n[0]-'0'-1))*(t-1)*9;
		//cout<<ans<<endl;
		ll c=0;
		c++;
		t--;
		while(n[c]=='0'&& c< n.size()){
			c++;
			t--;
		}
		if (c==n.size()){
			cout<<ans<<endl;
			return 0;
		}
		ans+=(t-1)*9+n[c]-'0';
		cout<<ans<<endl;
	}
	else if(k==3){
		if(t<3){
			cout<<0<<endl;
			return 0;
		}
		ans+=(t-1)*(t-2)*(t-3)/(ll)6*(ll)(9*9*9);
		ans+=max((ll)0,(ll)(n[0]-'0'-1))*(t-1)*(t-2)/2*(ll)(9*9);\
		//cout<<ans<<endl;
		ll c=0;
		c++;
		t--;
		while(n[c]=='0'&&c< n.size()){
			c++;
			t--;
		}
		if(c==n.size()){
			cout<<ans<<endl;
			return 0;
		}
		ans+=(t-1)*(t-2)/2*(ll)(9*9);
		ans+=max((ll)0,(ll)(n[c]-'0'-1))*(t-1)*9;
		//cout<<ans<<endl;
		c++;
		t--;
		while(n[c]=='0'&&c< n.size()){
			c++;
			t--;
		}
		if(c==n.size()){
			cout<<ans<<endl;
			return 0;
		}
		ans+=(t-1)*9+n[c]-'0';
		cout<<ans<<endl;
	} 
	return 0;	
} 
 
