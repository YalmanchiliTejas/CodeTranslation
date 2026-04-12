#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;

//二項係数
//参考 http://drken1215.hatenablog.com/entry/2018/06/08/210000
#define MAX 100005
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int find1(string s,int x){
    if(x>=s.length()) return 0;
    int a=s[x]-'0';
    return 9*(s.length()-1-x)+a;
}

int find2(string s,int x){
    if(x>=s.length()) return 0;
    int a=s[x]-'0';
    int i=x+1;
    while(s[i]-'0'==0&&i<s.length()) i++;
    return COM(s.length()-1-x,2)*pow(9,2)+find1(s,i)+(a-1)*(s.length()-1-x)*9;
}

int find3(string s,int x){
    int a=s[x]-'0';
    int i=x+1;
    while(s[i]-'0'==0&&i<s.length()) i++;
    return find2(s,i)+COM(s.length()-1-x,3)*pow(9,3)+(a-1)*COM(s.length()-1-x,2)*pow(9,2);
}

int main(){
    COMinit();
    string s;
    int k;
    cin>>s>>k;
    if(k==3) cout<<find3(s,0);
    else if(k==2)cout<<find2(s,0);
    else cout<<find1(s,0);
    cout<<endl;
}