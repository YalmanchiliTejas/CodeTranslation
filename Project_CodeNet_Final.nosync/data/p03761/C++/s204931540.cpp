//
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<algorithm>
#include<cmath>

#include<cstring>
#include<string>
#include<cctype>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<list>

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;

const int OO=(int)2e9;
const ll INF=(ll)4e18;
const double EPS=(double)1e-12;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

#define INL(i,a,b) ((a<=i)&&(i<=b))
#define EXL(i,a,b) ((a< i)&&(i< b))
#define REPP(i,a,b,c) for(int i=a;i<=b;i+=c)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,c) for(int i=a;i>=b;i-=c)
#define REV(i,a,b) REVV(i,a,b,1)
using namespace std;

int n,l;
int dat[55][55];
char s[55];

int main(){
	REP(i,0,53) REP(j,0,53)dat[i][j]=0;
	scanf("%d",&n);
	REP(i,1,n){
		scanf("%s",s);
		l=strlen(s);
		REP(j,1,l)dat[i][s[j-1]-'a']++;
	}
	REP(j,0,25){
		dat[52][j]=OO;
		REP(i,1,n)dat[52][j]=min(dat[52][j],dat[i][j]);
	}
	REP(j,0,25) while(dat[52][j]--)printf("%c",j+'a');
	puts("");
	return 0;
}