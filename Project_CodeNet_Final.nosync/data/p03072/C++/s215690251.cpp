#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long i = 0; i < n; i++)
#define erep(i, n) for(long i = 1; i <= n; i++)
const long MOD = 1000000007;
#define all(a) a.begin(), a.end()
#define eall(a) a.begin()+1, a.end()
#define show(ans)  cout << ans << endl;

int main(){
long N;
cin >> N;
vector<long> h(N+1);
erep(i, N) cin >> h[i];
long maxh = h[1];
long cnt = 0;
erep(i, N){
    if(h[i] >= maxh){
        cnt++;
        maxh = h[i];
    } 
// show(maxh);
}
show(cnt);

return 0;
}