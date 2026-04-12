#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    vector<int> ans;
    int pos;
    char left_hand[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
    while(true){
        int cnt = 0;
        pos = -1;
        string S; cin >> S;
        int lenS = S.length();
        if(lenS == 1 && S[0] == '#') break;
        rep(i, S.length()){
            char op = S[i];
            bool left = false; //0 -> right, 1 -> left
            rep(j, 15) if(op == left_hand[j]) left = true;
            if(pos == -1) pos = left;
            else if((pos == 0 && left) || (pos == 1 && !left)){
                cnt++;
                pos = !pos;
            }
            //cout << S[i] << ": " << left << endl;
        }
        ans.push_back(cnt);
    }
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}
