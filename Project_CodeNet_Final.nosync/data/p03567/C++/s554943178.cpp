#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 1e5+5;
char s[10];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C') {
			cout<<"Yes";return 0;
		}
	}
	cout<<"No";return 0;
 } 