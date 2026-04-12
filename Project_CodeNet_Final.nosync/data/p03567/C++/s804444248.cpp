#include <bits/stdc++.h>
#define REP(i,x,y) for(int i=(int)x;i<=(int)y;i++)
#define PER(i,x,y) for(int i=(int)x;i>=(int)y;i--)
#define FOR(i,x,y) for(int i=(int)x;i< (int)y;i++)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
const   int N=100005;
const   int P=1e9+7;


char s[N];
int main(){
	scanf("%s",s+1);
	FOR(i,1,strlen(s+1)){
		if(s[i]=='A'&&s[i+1]=='C'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
    return 0;
}