/*" بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ -In the name of Allah."
   Never stop chasing!-MD.SOURAV.

   ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
   ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
   ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
   [███████████████████].░░░░░░░░░░░░░░
   ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░
*/

#include <bits/stdc++.h>


#define endl           "\n"
#define MAX            32000
#define F              first
#define S              second
#define sz(x)          x.size()
#define li             long int
#define gcd(a,b)       _gcd(a,b)
#define pb             push_back
#define asrt(a,n)      sort(a,a+n)
#define MOD 	       1000000007
#define ll             long long int
#define lcd(a,b)       (a*b)/gcd(a,b)
#define mp(x,y)        make_pair(x,y)
#define no             cout<<"NO"<<endl
#define yes            cout<<"YES"<<endl
#define f(i, a, n)     for(int i=a;i<n;i++)
#define test           int t;cin>>t;while(t--)
#define srt(v)         sort(v.begin() , v.end())
#define basrt(a,n)     sort(a,a+n, greater<int>())
#define deb(x)         cout << #x<< ": "<< x<< endl;
#define sumof(x)       accumulate(x.begin(),x.end(),0);
#define rsrt(v)        sort(v.begin(),v.end(),greater<int>())
#define enter(v,n)     for(ll i=0;i<n;i++){ll x;cin>>x;v.pb(x);}
#define unique(v)      v.erase(unique(v.begin(),v.end()),v.end())
#define start          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ignore         cin.ignore (std::numeric_limits<std::streamsize>::max(),'\n');



using namespace std;

double pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664 ;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef map<ll,ll> mllll;
typedef map<char,ll> mchll;
typedef map<string,ll> msll;
typedef vector<pair<ll,ll>> vpllll;
typedef vector<pair<int,int>> vpiiii;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v) os << " " << x;
        return os << '}';
}


void solve()
{

    int n;
    cin>>n;
    vll  v;
    enter(v,n);
    ll ans=0;
    ll sum=0;
    for(int i=0;i<n;i++)
	{
		ans+=v[i]*sum;
		ans%=MOD;
		sum+=v[i];
		sum%=MOD;
	}
	cout << ans;





}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test_case=1;
    //cin>>test_case;
    while(test_case--)
	{
		solve();
	}

	return 0;
}