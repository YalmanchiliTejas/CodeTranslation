#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define PB push_back
#define LL long long
#define pii pair<LL,LL>
#define MEM(x,y) memset(x,y,sizeof(x))
#define bug(x) cout<<"debug "#x" is "<<x<<endl;
#define FIO ios::sync_with_stdio(false);
#define ALL(x) x.begin(),x.end()
#define LOG 20
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)
const int maxn=2e5;


int main(){
    FIO;
    string str;
    cin>>str;
	if((str[0]=='A'&&str[1]=='A'&&str[2]=='A')||
	(str[0]=='B'&&str[1]=='B'&&str[2]=='B'))
		puts("No");
	else
		puts("Yes");
    return 0;

	return 0;
}
