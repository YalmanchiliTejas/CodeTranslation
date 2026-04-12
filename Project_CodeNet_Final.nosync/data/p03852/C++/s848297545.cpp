#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long lng;
#define UP(i,a,b) for(int i=(a); i<=(b); ++i)
#define DOWN(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) UP(i,0,n-1)
#define ALL(a) (a).begin(), (a).end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end()) //NOTE: <a> must be sorted in advance

lng power(lng b, lng n) {lng sol=1; while(n>0) {if(n&1) {sol=sol*b;} n>>=1; b*= b;} return sol;} //calculate b^n

const int MOD = 1000000007; //10^9+7


/*********** variables ************/

/**********************************/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    char c;
    cin >> c;
    char vo[] = {'a','i', 'u', 'e', 'o'};
    REP(i, 5) {
        if(c==vo[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}
