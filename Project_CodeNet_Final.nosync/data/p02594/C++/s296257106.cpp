#include <bits/stdc++.h>
#define Mashu cout << "UUZ ate it." << endl
#define RE register int
#define ll long long
using namespace std;

inline int read(){
	char ch=getchar();
	int x=0,cf=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-') cf=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*cf;
}

int G[55];
template<class T> inline void write(T x){
	int g=0;
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

int main(){
	int x;
	cin >> x;
	if (x >= 30) cout << "Yes" << endl;
	else cout <<"No" << endl; 
	return 0;
	Mashu;
}
