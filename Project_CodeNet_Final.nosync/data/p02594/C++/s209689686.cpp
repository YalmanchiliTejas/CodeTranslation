#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uu unsigned
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mkp make_pair
#define ss second
#define ff first
#define mit(a,b) map<a,b>::iterator
#define sit(a) set<a>::iterator
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define pprint(x) print(x),putchar(' ')
#define fprint(x) print(x),putchar('\n')
#define printcas cout<<"Case "<<cas<<": "
#define _ continue;
#define endl '\n'
#define __ cout<<endl;continue;
#define vec4d(nam,type,a,b,c,d,fix) vector<vector<vector<vector<type>>>> nam(a,vector<vector<vector<type>>>(b,vector<vector<type>>(c,vector<type>(d,fix))))
const ll oo=(1ll<<60);
int gi(){
    int x=0,w=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')w=0,ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return w?x:-x;
}
void print(ll x)
{
    if(x < 0) putchar('-'),x = -x;
    if(x > 9) print(x / 10);putchar(x % 10 + '0');
}
int main()
{
     io;
    int T=1;
    //T=gi();
    //cin>>T;
    //for(int cas=1;cas<=T;cas++)
    while(T--)
    {
       int x=gi();
       puts((x>=30)?"Yes":"No");
    }
    return 0;
}
