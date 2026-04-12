#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
#define M 1000000007ll
#define UQ(x) (x).resize(distance((x).begin(),unique(all((x)))))
int h,w;
char s[15][15];
int main() {
	scanf("%d%d",&h,&w);
	for (int i=0;i<h;i++) scanf("%s",s[i]);
		bool die=0;
	for (int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			for (int x=0;x<h;x++) {
				for (int y=0;y<w;y++) {
					if (s[i][j]=='#' && s[x][y]=='#' && i>x && j<y) {
						die=1;
						break;
					}
				}
			}
		}
	}
	printf("%s\n", die?"Impossible":"Possible");
}