#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef map<ll, ll>    mp;
typedef pair<int, int>    pii;
typedef vector<ll>        vi;
typedef vector<pii>        vpii;
typedef vector<vi>        vvi;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
int m = 1000000007;
	int n;
	cin >> n;
	vi a(n);
	fo(i, n)cin >> a[i];
ll sum=0,sum1=0;
//vi temp;
for(int i=0;i<n;i++){
	sum1 +=a[i];
	sum1%=m;
}

for(int i=0;i<a.size();i++){
sum1-=a[i];
   if (sum1 < 0) sum1 += m;
sum+=a[i]*sum1;
sum%=m;
}
cout<<sum<<endl;
return 0;
}