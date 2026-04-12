#include <bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<b;i++)
#define per(i,a,b) for(register int i=b;i>=a;i--)
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Forenska(it,c) for(register __typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long LL;
typedef pair<LL,LL> Pair;
typedef vector<LL> vec;
const long double PI=3.14159265358979323846264338327950288;
const LL INF=0x3f3f3f3f3f3f3f3f;
int main()
{
	char ch=getchar();
	(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') && cout<<"vowel"<<endl;
	!(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') && cout<<"consonant"<<endl;
	return 0;
}
