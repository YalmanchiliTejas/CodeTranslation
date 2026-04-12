#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
#define PI acos(-1)
#define fi first
#define se second
#define lowbit(x) (x&(-x))
#define mp make_pair
#define pb push_back
#define ins insert
#define si size()
#define E exp(1.0)
#define fixed cout.setf(ios::fixed)
#define fixeds(x) setprecision(x)
#pragma GCC optimize(2)
using namespace std;
inline ll read(){ll s=0,w=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
return s*w;}void put1(){ puts("Yes") ;}void put2(){ puts("No") ;}
void debug(){printf("T   A   T\n");}void put3(){ puts("-1"); }ll qpf(ll a, ll b, ll p)
{ll ret = 0;while(b){if(b & 1) ret = (ret + a) % p;a = (a + a) % p;b >>= 1;}
return ret % p ;}ll qp(ll a, ll n, ll p){ll ret = 1;while(n){if(n & 1) ret = qpf(ret, a, p);
a = qpf(a, a, p);n >>= 1;}return ret % p ;}//��=acos(L/2R);
//void say(){ cout<<"I CAN AC"<<endl;}

const int manx=1e6+5;
const double eps =1e-8;


int main()
{
    string s; cin>>s;
    ll a=0,b=0;
    for(int i=0;i<s.si;i++){
        if(s[i]=='A') a++;
        else b++;
    }
    if(a&&b) put1();
    else put2();
    return 0;
}

