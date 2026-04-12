/*|In The Name Of Allah|*/
//This Month Will Be Expert ISA
#include <bits/stdc++.h>

using namespace std;

int n;
int k;
string s;
int mem[111][2][4][2];

int go(int idx , int les , int lft , int smS){
    if(idx == n)
        return lft == 0;
    if(~mem[idx][les][lft][smS])
        return mem[idx][les][lft][smS];
    int cnt = 0;
    for(int i = ((idx == 0) ? 1 : 0); i <= 9; i++){
        if( les && lft - (i != 0) >= 0 && smS ){
            cnt += go(idx + 1 , 1 , lft - (i != 0) , smS);
        } else if( !les && i <= s[idx] - '0' && lft - (i != 0) >= 0 && smS ){
            bool nwles = (i < s[idx]-'0');
            cnt += go(idx + 1 , nwles , lft - (i != 0) , smS);
        } else if(!smS && lft - (i != 0) >= 0) {
            cnt += go(idx + 1 , 1 , lft - (i != 0) , smS);
        }
    }
    return mem[idx][les][lft][smS] = cnt;
}

int main(){
    cin >> s >> k;
    memset(mem , -1 , sizeof mem);
    int ans = 0;
    for(int i = 1; i <= s.size(); i++){
        memset(mem , -1 , sizeof mem);
        n = i;
        ans += go(0 , 0 , k , i == s.size());
    }
    cout << ans << endl;
}
