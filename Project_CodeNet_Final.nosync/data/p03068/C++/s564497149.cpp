#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include <map>
using namespace std;
typedef long long int ll;
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,a) repi(i,0,a)
#define all(u) u.begin(),u.end()
#define pl pair<ll,ll>
#define fi first
#define se second
#define mod 1000000007
#define inf 1<<30
#define mp(a,b) make_pair(a,b)
#define len(u,N) u.begin(),u.begin()+N


ll N,K;
string S;

int main() {
    cin >> N;
    cin >> S;
    cin >> K;
    char c = S[K-1];
    rep(i,N){
        if (S[i] != c){
            S[i] = '*';
        }
    }
    cout << S << endl;
    return 0;
}
