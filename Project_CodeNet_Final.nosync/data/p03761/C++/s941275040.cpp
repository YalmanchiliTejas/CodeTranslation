#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<string> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<vector<int> > ans(N,vector<int>(26));
    rep(i,N){
        int len = vec[i].size();
        rep(j,len){
            ans[i][vec[i][j] - 'a']++;
        }
    }
    vector<int> ans_copy(26);
    rep(i,26){
        int minim = 51;
        rep(j,N){
            minim = min(ans[j][i], minim);
        }
        ans_copy[i] = minim;
    }
    string str_ans = "";
    rep(i,26){
        int len = ans_copy[i];
        rep(j,len){
            if (i == 0) str_ans += "a";
            if (i == 1) str_ans += "b";
            if (i == 2) str_ans += "c";
            if (i == 3) str_ans += "d";
            if (i == 4) str_ans += "e";
            if (i == 5) str_ans += "f";
            if (i == 6) str_ans += "g";
            if (i == 7) str_ans += "h";
            if (i == 8) str_ans += "i";
            if (i == 9) str_ans += "j";
            if (i == 10) str_ans += "k";
            if (i == 11) str_ans += "l";
            if (i == 12) str_ans += "m";
            if (i == 13) str_ans += "n";
            if (i == 14) str_ans += "o";
            if (i == 15) str_ans += "p";
            if (i == 16) str_ans += "q";
            if (i == 17) str_ans += "r";
            if (i == 18) str_ans += "s";
            if (i == 19) str_ans += "t";
            if (i == 20) str_ans += "u";
            if (i == 21) str_ans += "v";
            if (i == 22) str_ans += "w";
            if (i == 23) str_ans += "x";
            if (i == 24) str_ans += "y";
            if (i == 25) str_ans += "z";
        }
    }
    cout << str_ans << endl;
}
