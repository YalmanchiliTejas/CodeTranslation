#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<set>
#include<stack>
#include<complex>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
#define bv vector<bool>
using namespace std;
typedef pair<int, int>PI;
using namespace std;
#define MAX  999999
int main(){
    while(true){
    int n,a,b,c,x; cin >> n >>a >> b >> c>> x;
        if(n+a+b+c+x == 0) break;
        vi v(10000,0); rep(i,n) cin >> v[i];
        vi ans(10000,0); int cnt = 0; int kotae =-1;
        rep(i,10001){
            if(i == 0){ans[i+1] = (a*x+b)%c; ans[i] = x;}
            else ans[i] = (a*ans[i-1]+b)%c;
            if(v[cnt] == ans[i]){cnt++;}
            if(cnt == n) {kotae= i;break;}
        }
        cout << kotae << endl;
    }
}