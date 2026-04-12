#include<cmath>
#include<bits/stdc++.h>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a>b? b:a)
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#define repr(i,n) for(lint i=(lint)(n);i>0;--i)
#define reps(i,a,b) for(lint i=a;i<=(lint)(b);i++)
typedef long long lint;
typedef long double ld;
using namespace std;
const ld PI = acos(-1.0);

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i,N) cin >> H[i];
    int max=H[0];
    int cnt = 1;
    rep(i,N-1) {
        max=MAX(max,H[i]);
        if(H[i+1]>=max) cnt++;
    }
    cout << cnt << endl;
	return 0;
}