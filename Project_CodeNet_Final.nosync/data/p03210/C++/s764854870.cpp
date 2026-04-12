#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<math.h>
#include<bitset>
#include<random>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(17)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<char,P> Q;
//ll longinf=1ll<<60;
int inf=1<<29;
ll longinf=(1ll<<60);

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};



int main(){
    int a;
    cin>>a;
    if(a%2==1&&a>=3&&a<=7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
