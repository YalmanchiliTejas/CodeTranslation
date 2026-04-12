#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775807;
const ll half_inf = 0x3f3f3f3f;
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const ll maxn = 200005;
const ll N = 500005;
char s[10]; 
void solve(){
	
}
int main(){  
	cin.tie(0); 
    ios::sync_with_stdio(false);
	/*int T,n,m,k,sum=0;
	scanf("%d",&T); 
	while(T--){
		//solve();	
		
	}*/
	int a=0,b=0;
	scanf("%s",s);
	for(int i=0;i<3;i++){
		if(s[i]=='A') a++;
		if(s[i]=='B') b++;
	}
	if(a==0||b==0) printf("No");
	else printf("Yes");
	return 0;
}
