#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int f(VI n, int k){
    while(n.back() == 0){
        n.pop_back();
    }
    int len = n.size();
    if(len < k) return 0;
    if(k == 1){
        return 9*(len-1) + n.back();
    }else{
        VI m(len-1, 9);
        int n0 = n.back();
        n.pop_back();
        return f(m,k) + (n0-1)*f(m,k-1) + f(n,k-1);
    }
}

int main(){
    string s;
    int k;
    cin >> s >> k;

    int len = s.size();
    VI n(len);
    rep(i,len){
        n[i] = s[len-i-1] - '0';
    }

    cout << f(n,k) << endl;

    return 0;
}