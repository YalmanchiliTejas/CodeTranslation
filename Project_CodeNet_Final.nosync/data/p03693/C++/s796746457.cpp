#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int r, g, b;

int main(void){
	
	scanf("%d %d %d", &r, &g, &b);
	
	if((r * 100 + g * 10 + b) % 4 == 0) printf("YES\n");
	else printf("NO\n");
	
    return 0;
}
