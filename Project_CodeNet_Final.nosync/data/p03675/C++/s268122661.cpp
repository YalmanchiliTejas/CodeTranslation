#include<set>
#include <unordered_set>
#include <unordered_map>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include<math.h>
#include <string.h>
#include <strings.h>


#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=(a);i<=(int)(n);++i)
#define lpd(i,a,n) for(int i=(a);i>=(int)(n);--i)
#define clr(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define readll(x) scanf("%I64d",&x)
#define mod 1000000007
#define eps 1e-10
#define infi  1000000000ll
#define infll 1000000000000000000ll


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef unordered_map<ll,ll> umll;


const int N = 200003;
int n,a[N],b[N];
int main(){
    scanf("%d",&n);
    lp(i, 1, n) scanf("%d",&a[i]);
    if(n&1) {
        b[n/2 + 1] = a[1];
        lp(i, 1, n/2) b[n/2+1+i] = a[2*i], b[n/2+1-i] = a[2*i+1];
        
    } else  {
        lp(i, 1, n/2) b[n/2-i+1] = a[2*i];
        lp(i, 1, n/2) b[n/2+i] = a[2*i-1];

     }
    
    lp(i, 1, n) printf("%d ",b[i]);
    printf("\n");
    return 0;
}



/*
 */

//ios::sync_with_stdio(0);cin.tie(0);