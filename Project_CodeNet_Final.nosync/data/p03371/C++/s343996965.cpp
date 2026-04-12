#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;

int main(){
    Int a,b,c,x,y;cin >> a >> b >> c >> x >> y;
    Int ans = 0;
    //cout << " start" << endl;
    if((a+b)>=(2*c)){
        if(x<=y){
            ans+= 2*c*x;
            y-=x;
            x = 0;
        }else{
            ans+=2*c*y;
            x-=y;
            y = 0;
            //cout << "bin " << endl;
        }
    }
    if(2*c<=a) {ans+=2*c*x;x=0;}
    if(2*c<=b) {ans+=2*c*y;y=0;}
    ans+=x*a;
    ans+=y*b;
    cout << ans << endl;

}