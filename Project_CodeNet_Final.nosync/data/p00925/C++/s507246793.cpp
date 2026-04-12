#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define first fi;
#define second se;
using namespace std;
typedef pair<int, int> P;

signed main(){
    string s;
    int a;
    cin >> s >> a;
    s += "+0";
    vector<int> d;
    int now = s[0] - '0';
    int nowl = now;
    rep(i, 0, s.size() / 2){
        
        char c = s[i * 2 + 1];
        int tmp = s[i * 2 + 2] - '0';
        if(c == '+'){
            now += tmp;
            d.push_back(nowl);
            nowl = tmp;
         }else{
             now *= tmp;
             nowl *= tmp;
         }
    }
    int sum = 0;
    rep(i, 0, d.size()) sum += d[i];
    if(a == sum && a == now) cout << "U" << endl;
    else if(a == sum) cout << "M" << endl;
    else if(a == now) cout << "L" << endl;
    else cout << "I" << endl;
}