#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

using ull = unsigned long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vull = vector<ull>;
using vpii = vector<pii>;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rFOR(i,a,b) for(int i=(b);i>=(a);i--)
#define SORT(a) sort((a).begin(),(a).end());
#define rSORT(a) sort((a).rbegin(),(a).rend());
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;

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

    int r,g,b;
    cin >>r>>g>>b;
    YN((r*100+g*10+b)%4==0);

    return 0;
}