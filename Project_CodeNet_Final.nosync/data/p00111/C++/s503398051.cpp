#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

string str[32]={"101",
                "000000",
                "000011",
                "10010001",
                "010001",
                "000001",
                "100101",
                "10011010",
                "0101",
                "0001",
                "110",
                "01001",
                "10011011",
                "010000",
                "0111",
                "10011000",
                "0110",
                "00100",
                "10011001",
                "10011110",
                "00101",
                "111",
                "10011111",
                "1000",
                "00110",
                "00111",
                "10011100",
                "10011101",
                "000010",
                "10010010",
                "10010011",
                "10010000"};
string af=" ',-.?";
string bf=" .,-'?";
 
string change_to_2(int n){
    string res = "";
    rep(i, 0, 5){
        res += '0' + n % 2;
        n /= 2;
    }
    reverse(all(res));
    return res;
}
 
signed main(){
    string s;
    while(getline(cin, s)){
        string tmp = "", ans = "";
        rep(i, 0, s.size()){
            if('A' <= s[i] && s[i] <= 'Z'){
                tmp += change_to_2(s[i] - 'A');
            }else{
                int p = bf.find(s[i]);
                tmp += change_to_2(p + 26);
            }
        }
        //cout << tmp <<endl;
        rep(i, 0, tmp.size()){
            bool f = false;
            int p;
            rep(j, 0, 32){
                if(str[j] == tmp.substr(i, (int)(str[j].size()))){
                    p = j; f = true; i += (int)(str[j].size()) - 1;
                    break;
                }
            }
            if(!f) break;
            if(p >= 6){
                ans += (char)('A' + (p - 6));
            }else{
                ans += af[p];
            }
        }
        cout << ans << endl;
    }
}