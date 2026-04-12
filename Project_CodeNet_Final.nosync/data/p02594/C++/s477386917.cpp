#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define re register
using namespace std;
#define gc getchar
inline int read(){
	int t=0,f=0;
	char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
int n;
signed main(){
	scanf("%d",&n);
	puts((n>=30)?"Yes":"No"); 
}