#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
bool find(string s,char c){
    for(char cc:s){
        if(c == cc)return 1;
    }
    return 0;
}
main(){
    string s1 = "qwertasdfgzxcvb";
    string S;
    cin >> S;
    while(S != "#"){
        int turn,cnt = 0;
        turn = find(s1, S[0]);
        rep(i,0,S.size()){
            if(turn != find(s1, S[i])){
                cnt++;
                turn = find(s1, S[i]);
            }
        }
        cout << cnt << endl;
        cin >> S;
    }
}
