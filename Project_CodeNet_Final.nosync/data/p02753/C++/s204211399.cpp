#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
#define REPR(i,n) for(int i = n; i >= 0; i--)
#define FOR(i,m, n) for(int i = m-1; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))
#define FILL2D(A,c) fill(A[0], A[0] +sizeof(A)/sizeof(**A),c)
#define FILL3D(A,c) fill(A[0][0], A[0][0] +sizeof(A)/sizeof(***A),c)
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin >>s;
    if(s[0]==s[1]&&s[1]==s[2])cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
