#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc_m(string s){
    stack<ll> num;
    stack<char> ope;
    for(auto c : s){
        if(c >= '0' && c <= '9'){
            num.push(c-'0');
            if(!ope.empty() && ope.top() == '*'){
                ll n1, n2;
                n2 = num.top(), num.pop();
                n1 = num.top(), num.pop();
                num.push(n1*n2);
            }
        }
        else ope.push(c);
    }
    ll res = 0;
    while(!num.empty()){
        res += num.top();
        num.pop();
    }
    return res;
}

ll calc_l(string s){
    ll res = s[0] - '0';
    for(int i=1;i<int(s.size());i+=2){
        if(s[i]=='+'){
            res += s[i+1]-'0';
        }
        else{
            res *= s[i+1]-'0';
        }
    }
    return res;
}

int main() {
    string s;
    ll x, m, l;
    cin >> s >> x;
    m = calc_m(s);
    l = calc_l(s);
    if(x==m && x!=l){
        cout << 'M' << endl;
    }
    else if(x!=m && x==l){
        cout << 'L' << endl;
    }
    else if(x==m && x==l){
        cout << 'U' << endl;
    }
    else{
        cout << 'I' << endl;
    }
    return 0;
}
