#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

ll patty(ll N, ll X){
    if(N==0) return 1;
    if(X==1) return 0;
    ll MAXIM=pow(2, N+2)-3;
    ll NEXT=pow(2, N)-1;
    if(X==MAXIM) return NEXT*2+1;
    if(X==MAXIM/2+1) return NEXT+1;
    if(X<MAXIM/2+1) return patty(N-1, X-1);
    else return NEXT+1+patty(N-1, X-(MAXIM/2+1));
}

int main(void){
    ll N, X;
    cin>>N>>X;
    cout<<patty(N, X)<<endl;
    return 0;
}
