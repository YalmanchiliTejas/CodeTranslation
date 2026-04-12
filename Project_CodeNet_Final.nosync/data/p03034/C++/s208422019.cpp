#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n;
Int s[108000];
Int ss[108000];
Int ans = 0;
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }

    for(int d = 1;d < n;d++){
        Int tmp = 0;
        for(int kd = 0;kd < n-1;kd += d){
            int op = n-1 - kd;
            if(op <= kd && op % d == 0)break;
            tmp += s[kd] + s[op];
            if(op > d)
                ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}