#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define all(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
 
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

//
int main(void) {
    int N,K;
    string s;
    cin >> N >> s >> K;
    rep(i,s.size()){
        if(s[i]!=s[K-1]){
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}