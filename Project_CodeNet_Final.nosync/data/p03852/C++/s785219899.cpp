#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi atan(1.0)*4
#define pb(x) push_back(x)
#define in(x) insert(x)
#define fl(x,y) for(ll i=x;i<y;i++)
#define vi vector<long long>
#define vs  vector<string>
#define vp(vi,x) cin>>x; vi.pb(x);
string en="\n";
string t="hello";
string Y="YES\n";
string N="NO\n";
#define E end()
#define B begin()
#define sz size()
#define EM empty()
#define fi first
#define se second
#define clr clear()
#define sqr(a) (a*a)
#define mk make_pair
#define mem(a,b) memset(a,b,sizeof(a))
#define all(cont) cont.begin(),cont.end()
/*bool isprm(LL a){for(LL i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
bool palin(string a){for(int i=0;i<a.sz;i++){if(a.at(i)!=a.at(a.sz-i-1))return 0;} return 1;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
LL bpow(LL a,LL b){if(b==0)return 1;LL r=bpow(a,b/2);if(b%2)return r*r*a;else return r*r;}
LL binpow(LL a,LL b){LL r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
LL binpow(LL a,LL b,LL m){a%=m;LL r=1;while(b>0){if(b&1) r=r*a%m;a=a*a%m; b>>=1;}return r;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
*/
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
int main()
{
    ll a,b,c,t,n,k,p,q,r,y,yy,sum,ct=0,flag=0;
    string s,s1,s2,s3;
    set<ll>st;
    char ch;
    map<ll,ll>mp;
    vector<ll>v,vv,vz;

      cin>>ch;
      p=isVowel(ch);
      if(p) cout<<"vowel"<<endl;
      else cout<<"consonant"<<endl;


}



