#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=40005;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(s[i]!=s[j])
			{
				cout<<"Yes\n";
				return 0;
			}
		}
	}
	cout<<"No";
}
// When you want to succeed as bad as you want to breathe, only then you’ll Be Successful!
// No Matter,How Fast You Are Driving If You Are Driving in a Wrong Direction You Will Never Reach Your Destination
// When failures hit you, you hit the failures back with Bounce Back!
// When you face failures, Don’t change your goal, Change your strategy!