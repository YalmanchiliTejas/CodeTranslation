#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi; 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int mod = 1e9+7;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
char str[maxn];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>str;
	if(str[0]==str[1]&&str[1]==str[2]) cout<<"No"<<'\n';
	else cout<<"Yes"<<'\n';
    return 0;
}
