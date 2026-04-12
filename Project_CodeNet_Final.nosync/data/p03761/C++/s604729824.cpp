#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define n_max 55


int main(){
    int n;
    cin >> n;
    int A[n_max][26];
    REP(i,n_max) REP(j,26) A[i][j]=0;
    string s;
    int ind;
    REP(i,n){
        cin >> s;
        itrfor(itr,s){
            for(ind=0;ind<26;ind++){
                if(*itr == moji[ind]) break;
            }
            A[i][ind] +=1;
        }
    }

    REP(i,26){
        FOR(j,1,n){
            A[0][i] = min(A[j][i] , A[0][i]);
        }
    }

    REP(i,26){
        REP(j,A[0][i]) cout << moji[i];
    }
    cout << endl;
}


