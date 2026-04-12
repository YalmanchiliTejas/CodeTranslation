#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 100005;
const int MOD = 1000000007;

char t[N];
string s;
int d, S[N][100], R[N][100], i, j, k, tab[N], n;

int main() {
scanf("%s", t);
s = t;
n = s.size();
for (i=0;i<n;i++) tab[i] = int(s[i]) - 48;
scanf("%d", &d);
for (i=0;i<=9;i++) S[0][i % d]++;
for (j=1;j<n;j++) for (i=0;i<=9;i++) for (k=0;k<d;k++) S[j][(k + i) % d] = (S[j][(k + i) % d] + S[j - 1][k]) % MOD;
for (i=0;i<=tab[n - 1];i++) R[0][i % d]++;
for (j=1;j<n;j++) {
	for (i=0;i < tab[n - 1 - j];i++) for (k=0;k<d;k++) R[j][(k + i) % d] = (R[j][(k + i) % d] + S[j - 1][k]) % MOD;
	i = tab[n - 1 - j];
	for (k=0;k<d;k++) R[j][(k + i) % d] = (R[j][(k + i) % d] + R[j - 1][k]) % MOD;
}
printf("%d\n", (R[n - 1][0] + MOD - 1) % MOD);
return 0;
}