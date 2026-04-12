#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define len(a) (int)a.size()
#define all(a) (a.begin(),a.end())
#define fi first
#define sc second
#define ort(x,y) (x+y)/2
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);
#define d1(x) cerr<<#x<<":"<<x<<endl;
#define d2(x,y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define d3(x,y,z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define lim (int) (1e5+5)
#define inf (int) (1e7)
#define heap priority_queue
#define mem(a,val) memset(a,val,sizeof(a))
#define y1 asdassa
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
char s[10];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<n;i++)
		if(s[i]=='A' && s[i+1]=='C') return printf("Yes"),0;
	printf("No");
}


