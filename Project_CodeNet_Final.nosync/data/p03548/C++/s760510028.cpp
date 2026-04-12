#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <stdio.h>
using namespace std;

typedef long long ll;

#define min(a, b) (((a) < (b))? (a):(b))
#define max(a, b) (((a) > (b))? (a):(b))
#define REP(i, a, n) for(int i=(a); i<(n); i++)
#define rep(i, n) REP(i, 0, (n))
#define square(a) (a)*(a)
#define pb push_back

int x,y,z;
int main(){
    cin >> x >> y >> z;
    int ans;
    ans = (x-z)/(y+z);
    cout << ans << endl;
}
