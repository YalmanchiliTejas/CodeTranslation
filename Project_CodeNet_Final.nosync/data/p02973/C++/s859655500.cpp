#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const ll INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

int a[100000];
int d[100000];

int main(void){
    int n; cin >> n; for(int i = 0;i < n;i++)cin >> a[i];
    fill(d, d + n, -2);
    for(int i = 0;i < n;i++){
        *(lower_bound(d, d + n, a[i]) - 1) = a[i];
    }
    printf("%d\n", n - (lower_bound(d, d + n, -1) - d));
	return 0;
}