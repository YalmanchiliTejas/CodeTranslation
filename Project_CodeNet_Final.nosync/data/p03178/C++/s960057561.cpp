#include <bits/stdc++.h>
using namespace std;

#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)

#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)

#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))

#define whileZ int T; getI(T); while(T--)
#define lastEle(vec) vec[vec.size()-1]
#define SZ(x) ((int)((x).size()))

#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int

#define mp make_pair
#define fi first
#define se second

// for debug
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)

#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

ll dp[10001][2][101];        // dp -- pos - tight - mod
string s;
int d;

ll getans (int pos, int tight, int mod)
{
    if (pos == s.size()) 
        return (ll)(mod==0);
    if (dp[pos][tight][mod]!=-1)
        return dp[pos][tight][mod];
    dp[pos][tight][mod] = 0LL;
    int en = tight ? (s[pos]-'0') : 9;
    FE(i,0,en)
        dp[pos][tight][mod] = (dp[pos][tight][mod] + getans (pos+1,tight&(i==en),(mod+i)%d)) % 1000000007LL;
    return dp[pos][tight][mod];
}

int main()
{
    cin >> s;
    memset(dp,-1,sizeof(dp));
    getI(d);
    cout << (getans(0,1,0) + 1000000006LL) % 1000000007LL << "\n";
    return 0;
}