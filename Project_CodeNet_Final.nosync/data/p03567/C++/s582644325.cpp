#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define lb(x) ((x)&(-(x)))
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define N 100010
using namespace std;
typedef long long ll;
int n;
char s[N];
int main(){
	scanf("%s",s),n=strlen(s);
	for(int i=0;i<n-1;i++)if(s[i]=='A'&&s[i+1]=='C')return puts("Yes"),0;
	puts("No");
	return 0;
}