#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;  typedef pair<ll, pi> plp;
typedef pair<int, pi> pip; typedef tuple<int, int, int> ti;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

char S[100]; int N;
int main() {
	scanf("%s", S);
	N = strlen(S);
	bool isGood = false;
	for(int i=0; i<N-1; i++) if(S[i] == 'A' && S[i+1] == 'C') isGood = true;
	puts(isGood?"Yes":"No");
	return 0;
}
