#include<cstdio>
#include<cstring>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define ran 222

int n;
int a[ran];
int p[ran];
vector<pair<int, int> > v;

int q(int x, int y) {
	char s[ran];
	for(int i=0;i<n;i++)
		s[i] = (i==x || i==y) ? '1' : '0';
	s[n] = 0;
	printf("? %s\n", s);
	fflush(stdout);
	
	int res = 0;
	scanf("%d", &res);
	return res;
}

int get_p(int x) {
	return p[x] == -1 ? x : p[x] = get_p(p[x]);
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) a[i] = i;
	srand(time(0));
	random_shuffle(a,a+n);
	//for(int i=0;i<n;i++) printf("%d ", a[i]);
	//puts("");
	memset(p, -1, sizeof p);
	v.clear();
	int todo = n-1;
	for(int i=0;i<n && todo;i++)
		for(int j=i+1;j<n && todo;j++) {
			//printf("-- %d %d\n", a[i], a[j]);
			int x = get_p(a[i]), y = get_p(a[j]);
			if(x!=y) {
				int ret = q(a[i], a[j]);
				if(ret) {
					p[x] = y;
					v.push_back(make_pair(a[i], a[j]));
					todo --;
				}
			}
		}
	printf("!");
	for(int i=0;i<v.size();i++)
		printf(" (%d,%d)", v[i].first, v[i].second);
	puts("");
	fflush(stdout);
	
	return 0;
}