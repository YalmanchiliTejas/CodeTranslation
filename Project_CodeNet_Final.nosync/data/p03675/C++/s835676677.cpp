// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

int n;
deque<int> Q;

int main() {
	n=read();
	for (int i=1;i<=n;++i) {
		int w=read();
		if (i&1) Q.push_back(w);
		else Q.push_front(w);
	}
	if (n&1) {
		while (!Q.empty()) printf("%d ",Q.back()),Q.pop_back();
	} else {
		while (!Q.empty()) printf("%d ",Q.front()),Q.pop_front();
	}
	return 0;
}