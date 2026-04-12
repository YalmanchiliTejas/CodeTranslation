//by tzupengwang™
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n;
int s[200005];
vector<int> v;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &s[i]);
    v.push_back(s[i]);
  }

  sort(v.begin(), v.end());
}

void process() {
  int c1 = v[n / 2 - 1], c2 = v[n / 2];

  for (int i = 0; i < n; i ++) {
    if (s[i] <= c1) printf("%d\n", c2);
    else printf("%d\n", c1);
  }
}

int main() {
/*
#ifdef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  int Cases;
  scanf("%d", &Cases);
  for (int cs = 1; cs <= Cases; cs ++) {
*/
    init();
    process();
/*
  }
*/
  return 0;
}
