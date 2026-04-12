#include <bits/stdc++.h>
using namespace std;

char Trump;
string cards[4][13];
string strength="23456789TJQKA";

int comp(string s,string t){
    if (s[1]==Trump&&t[1]!=Trump) return 1;
    if (s[1]!=Trump&&t[1]==Trump) return 0;
    if (s[1]!=t[1]) return 0;
    int s_strength,t_strength;
    for (int i=0;i<13;++i){
        if (s[0]==strength[i]) s_strength=i;
        if (t[0]==strength[i]) t_strength=i;
    }
    if (t_strength<s_strength) return 1;
    return 0;
}

void solve(){
    int ns=0,ew=0,winner=0;
    for (int j=0;j<13;++j){
        int nxt=winner; string Max=cards[winner][j];
        for (int i=1;i<4;++i){
            if (comp(cards[(winner+i)%4][j],Max)){
                Max=cards[(winner+i)%4][j]; nxt=(winner+i)%4;
            }
        }
        winner=nxt;
        ++(winner==0||winner==2?ns:ew);
    }
    cout << (ew<ns?"NS":"EW") << ' ' << max(ns,ew)-6 << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> Trump,Trump!='#'){
        for (int i=0;i<4;++i)
            for (int j=0;j<13;++j)
                cin >> cards[i][j];
        solve();
    }
}
