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
	if (cf < 0) return -x;
	else return x;
}

int G[55];
template<class T> inline void write(T x){
	int g=0;
	do{G[++g]=x%10;x/=10;}while(x);
	for(int i=g;i>=1;--i)putchar('0'+G[i]);putchar('\n');
}

long long qwq[500010];
int vis[500010];
long long qzh[500010];

long long QAQ(int n, int s){
	long long ans = 0;
	for (int i = s; i <= s + n - 1; i++){
		ans += qwq[i];
	} 
	return ans;
}

int main(){
	long long n, x, p;
	cin >> n >> x >> p;
	qwq[1] = x;
	qzh[1] = x;
	vis[x] = 1;
	for (int i = 2; i <= n; i++){
		qwq[i] = qwq[i - 1] * qwq[i - 1] % p;
		qzh[i] = qzh[i - 1] + qwq[i];
		if (vis[qwq[i]]){
			long long ovo = qzh[i] - qzh[vis[qwq[i]]];
			int awa = i - vis[qwq[i]];
			cout << qzh[i] + ((n - i) / awa) * ovo + QAQ((n - i) % awa, vis[qwq[i]] + 1);
			return 0;
		}
		else{
			vis[qwq[i]] = i;
		}
	}
	cout << qzh[n] << endl;
	return 0;
	Mashu;
}
