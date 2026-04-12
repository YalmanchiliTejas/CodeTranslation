#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
//#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
#define pi 3.141592653589793
using namespace std;
int saidaikouyakusuu(int a,int b){
    if(b==0) return a;
    return saidaikouyakusuu(b,a%b);
}
int saisyoukoubaisuu(int a,int b){
    return a*b/saidaikouyakusuu(a,b);
}
int n,m,cnt=INF,aa[220000],ans=0,o,x,y;
pair<string,int> pp[220000];
string s,sa[220000];
char c,ca[100][100];
queue<int> que;
signed main(){
    cin>>n>>m>>o>>x>>y;
    o*=2;
    rep(i,max(x,y)+1){
        cnt=min(cnt,i*o+max(0,x-i)*n+max(y-i,0)*m);
    }
    cout<<cnt<<endl;
}