#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rFOR(i,a,b) for(int i=(b);i>=(a);i--)
#define SORT(a) sort((a).begin(),(a).end());
#define rSORT(a) sort((a).rbegin(),(a).rend());
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end());
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;

const ll MOD = 1e9+7;

//sankou
//vvi = vector<vector<int>>(20, vector<int>(10, 0));

//seiki
//#include <regex>
/*bubun*/
//regex_search("u32", regex("[0-9]"));      // true
/*kanzen*/
//regex_match("u32", regex("(i|u)\\d+"));   // true

int isP(int n) {
    if(n<=1) return 0;
    FOR(i,2,(int)sqrt(n)) {
        if(n%i==0) return 0;
    }
    return 1;
}

int main() {

    ll N,K,cnt=0,n;
    cin >>N>>K;
    
    FOR(b,K+1,N){
        n=N/b;
        cnt+=(b-K)*n;
        if(N-(b*n)>=K) cnt+=(N-(b*n)-K+1);
        if(K==0) cnt--;
    }
    cout <<cnt<<endl;
    
    return 0;
}