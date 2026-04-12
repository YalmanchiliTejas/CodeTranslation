#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 1000000000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>//usage rand<long long>()
T rand() {
    return uniform_int_distribution<T>()(rng);
}

// string to integer stuuu()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
// #define int long long  

//////////

signed main()
{
	fastio;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	int ma=0;
	int ans=0;
	for(int i=0;i<n;++i)
		if(a[i]>=ma)
		{
			ans++;
			ma=a[i];
		}
	cout<<ans;
}