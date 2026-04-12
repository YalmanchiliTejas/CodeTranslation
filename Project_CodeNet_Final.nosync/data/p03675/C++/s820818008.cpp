#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const double PI = acos(-1.0);
const double eps = 1e-10;
int dcmp(double x) { if(fabs(x) < eps) return 0; else return x<0?-1:1; }
const int N = 5e5+5;

int a[N];

int main() {
    int n;
    scanf("%d", &n);
    int l = 2e5+6, r = 2e5+5;
    for(int i = 0; i < n; i++) {
        if(i & 1) scanf("%d", &a[++r]);
        else scanf("%d", &a[--l]);
    }
    if(!(n&1)) for(int i = r; i >= l; i--) printf("%d%c", a[i], i==l?'\n':' ');
    else for(int i = l; i <= r; i++) printf("%d%c", a[i], i==r?'\n':' ');
    return 0;
}
