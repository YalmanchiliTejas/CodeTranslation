#include<bits/stdc++.h>

#define int long long int
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repm(a,b,c) for(int a=(b-1);a>=c;a--)
#define pb push_back
#define str string
#define sf(a) scanfs("%d",&a)
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) (v).begin(), (v).end()

using namespace std;

const int INF = 1e18 + 9;
const int Mod = 1e9 + 7;
inline int replac(str s){double ans=0;rep(i,0,s.length()){ans+=(s[i]-'0')*pow(10,s.length()-i-1);}return (int)ans;}
inline string numstr(int m){str s="";while(m>0){char c;int a=m/10;if(a>0)a=m%(a*10);else a=m;c=(char)('0'+a);s+=c;m/=10;}str st="";for(int i=s.size()-1;i>=0;i--){st+=s[i];}return st;}
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
/**最小公倍数**/
int gcd( int m, int n )
{
	// 引数に0がある場合は0を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	// ユークリッドの方法
	while( m != n )
	{
		if ( m > n ) m = m - n;
        else n = n - m;
	}
	return m;
}//g
/**最大公約数**/
int lcm( int m, int n )
{
	// 引数に0がある場合は0を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int ma=lcm(n,m);
    int na=ma/n;
    int mma=ma/m;
    mma+=na;
    //cout << mma << " " << ma << endl;
    double ans=(double)ma/(double)mma;
    printf("%.10f\n",ans);
    return 0;
}
