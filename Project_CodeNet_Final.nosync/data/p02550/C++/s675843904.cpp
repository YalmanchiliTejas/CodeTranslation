#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	LL n,x,m;
    cin>>n>>x>>m;
    LL t=m,s=0;
    vl a(m,0),b(m+2,0);
    a[x]=1;b[1]=x;
    FOR(i,1,n){
        x=(x*x)%m;
        //cerr<<i<<" "<<x<<endl;
        if(a[x]!=0){
            t=i-a[x]+1;
            s=a[x]-1;
            break;
        }
        a[x]=i+1;
        b[i+1]=x;
    }
    //cerr<<s<<" "<<t<<endl;
    LL ans=0;
    FOR(i,0,s){
        ans+=b[i+1];
    }
    b[s]=0;
    FOR(i,s,s+t){
        b[i+1]+=b[i];
    }
    //cerr<<b[s+t]<<endl;
    n-=s;
    ans+=n/t*b[s+t];
    ans+=b[s+(n%t)];
    cout<<ans<<endl;
    
}
