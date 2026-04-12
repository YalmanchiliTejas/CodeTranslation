#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mp make_pair
#define CHECK(x) if(!(x)) return false;
#define CHECKRET(x, y) if(!(x)) return (y);
#define SKIP(x) if((x)) continue;
typedef pair<int, int> pii;

const int MAXN = 100010;
bool withmagic[MAXN];
int nomagic;
int nrMagic = 0;
int N;

void mkTrue(int pos) {
  if (pos < 0 || pos >= N) return;
  if (!withmagic[pos]) ++nrMagic;
  withmagic[pos] = true;
}

int main() {
  int Q;
  scanf("%d%d", &N, &Q);
  nomagic = 0;
  nrMagic = 0;
  while (Q--) {
    mkTrue(nomagic - 1);
    mkTrue(nomagic + 1);
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    if (nomagic == l) nomagic = r;
    else if (nomagic == r) nomagic = l;

    swap(withmagic[l], withmagic[r]);

    mkTrue(nomagic - 1);
    mkTrue(nomagic + 1);
  }

  mkTrue(nomagic);
  printf("%d\n", nrMagic);
  return 0;
}
