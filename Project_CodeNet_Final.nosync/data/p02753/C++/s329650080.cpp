// IlyM

#include <bits/stdc++.h>
#define pb push_back
#define sp " "
#define sl "\n"
#define fi first
#define se second
#define mp make_pair
#define sz(a) ((int)a.size())
#define tra(a,b) for (auto a:b) 
#define fo(a,b,c) for (int a=b;a<=c;a++) 
#define ms(a,b) memset(a,b,sizeof(a)) 
#define all(a) a.begin(),a.end()
#define rev(a) reverse(a.begin(),a.end())
#define bit(i,j) (i&(1<<j))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<int,ii> iii;

const int N=2e5+5,mod=998244353;
string a;
int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin>>a;
	if (a=="AAA" || a=="BBB") cout<<"No";
	else cout<<"Yes";
	return 0;
}
