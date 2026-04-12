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
#define print(a) cout << a << endl;
#define MAX 51



llong pmai[MAX];
llong allmai[MAX];

llong cnt(int lev,llong maisuu){
    llong ans=0;
    if(maisuu <= 1) return 0;
    maisuu -=1;
    if( allmai[lev-1] <= maisuu){

        ans += pmai[lev -1];

        maisuu -= allmai[lev -1];
    }
    else{
        ans += cnt(lev-1,maisuu);
        maisuu = 0;
    }
    if(maisuu == 0) return ans;
    maisuu -=1;
    ans += 1;
    if(maisuu == 0) return ans;
    if( allmai[lev-1] <= maisuu){
        ans += pmai[lev-1];
        return ans;
    }
    else{
        ans += cnt(lev-1,maisuu);
    }
    return ans;


}


int main(){
    int lev;
    llong x;
    cin >> lev;
    cin >> x;


    allmai[0] = 1;
    FOR(i,1,51) allmai[i] = 3 + 2 * allmai[i-1];


    pmai[0] = 1;
    FOR(i,1,51) pmai[i] = 1 + 2 * pmai[i-1];
   
    llong ans = cnt(lev,x);

    cout << ans << endl;
}