#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl

int main() {
    int x, y, z; cin >> x >> y >> z;

    int tmp = y + 2 * z;
    int cnt = 1;
    while(tmp<=x){
        cnt++;
        tmp += y + z;
    }

    cnt--;
    cout << cnt << endl;
}