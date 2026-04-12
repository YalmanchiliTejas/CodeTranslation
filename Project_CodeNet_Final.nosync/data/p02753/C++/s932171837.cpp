#include <bits/stdc++.h>
using namespace std;


void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

#define ll long long
#define ld long double
#define ull unsigned long long
#define ull unsigned long long
#define mod 1000000007
#define pi (3.1415926)

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define scd(a)  scanf("%lld",&a)
#define scdd(a,b)	scanf("%lld%lld",&a,&b)
#define scddd(a,b,c)	scanf("%lld%lld%lld",&a,&b,&c)
#define ptab(a)	printf("%lld ",a)
#define pdn(a)	printf("%lld\n",a)
#define pddn(a,b)	printf("%lld %lld\n",a,b)
#define pdddn(a,b,c)	printf("%lld %lld %lld\n",a,b,c)

#define Filein(N) freopen("N", "r", stdin);
#define Fileout(N) freopen("N", "w", stdout);

#define forr(n) for(ll i=0;i<n;i++)
#define rev(n) for(ll i=n-1;i>=0;i--)
#define forp(x, y) for(ll i=x;i<y;i++)
#define loop( j, k, in) for (ll i=j ; i<k ; i+=in)

#define in  cin>>
#define out cout<<
#define en "\n"
#define sp " "
#define eps 1.0E-14
#define l length()
#define preci(x) fixed<<setprecision(x)
#define inf LONG_LONG_MAX
#define ninf LONG_LONG_MIN
int N;
char ans[111];

void odd(int n)
    {
    bool b=1;
        int x = sqrt(n);
    for (int i=2 ; i<=x ; ++i)

    {
        if(n%i == 0) {cout << "NO" << sp; b = 0;  break;}
    }
    if (b)
    cout << "Yes" << sp;
    b=1;
    }


void DFS(int cur,int mx){
//    printf("cur = %d\n",cur);
    if(cur==N){
        ans[N]='\0';
        printf("%s\n",ans);
        return;
    }
    for(int i=0;i<=cur;i++){
        ans[cur]='a'+i;
        DFS(cur+1,max(mx,i));
        if(i>mx) break;
    }
}

void work(){
    scanf("%d",&N);
    DFS(0,0);
}

ll sum (int n ){return ((n*(n+1)) / 2) ;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main()
{
    init();
    
    string s; cin>>s;
    
    if (s[0] == s[1] && s[1] == s[2]) cout << "No";
    else cout << "Yes";
}
