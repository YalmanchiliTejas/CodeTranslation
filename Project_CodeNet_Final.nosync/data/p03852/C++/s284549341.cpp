#include<bits/stdc++.h>                                                                                                                  
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
             
#define pb push_back
#define PII pair<int,int>
             
#define VS vector<string>
#define VI vector<int>
#define ll long long int
#define debug(x) cout << x << " :" <<#x << endl  
int main(void) {
    string s = "aiueo";
    char c; cin >> c;
    bool p = false;
    REP(i,5) {
        if(c == s[i]) {
            p = true;
            break;
        }    
    }        
    if(p) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}