
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
// memo  fixed  setprecision(20);
using vvll = vector<vector<ll>>;
ll mod =1000000007;
/*"itob" int to "N"base */           template<typename TypeInt> string itob(const TypeInt v, int base){static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";string ret;static numeric_limits<TypeInt> t;TypeInt n = v;if (t.is_signed) {if (v < 0) n *= -1;}while (n >= base) {ret += table[n%base];n /= base;}ret += table[n];if (t.is_signed) {if (v < 0 && base == 10) ret += '-';}reverse(ret.begin(), ret.end());return ret;}
/*"chmin" a = MAX*/                  template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
/*"chmax" a = MIN*/                  template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/*"ctoi"  char to int*/              int ctoi(char c) {return c-'0';}
/*"gcd"   MAX*/                      ll gcd(ll a,ll b){if(b==0)return a; return gcd(b,a%b);}
/*"lcm"   MIN*/                      ll lcm(ll a,ll b){ll g = gcd(a,b);return a/g*b;}
/*"primecheck"If prime,return true.*/bool primecheck(ll n){if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
string  reverserange(string s,ll a,ll b){reverse(s.begin()+a-1,s.begin()+b); return s;}
int main(){
    int n;
    cin >> n;
    vector<map<char,int>>a(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            if(!a.at(i).count(s.at(j))){
                a[i][s.at(j)]=1;
            }
            else {
               a[i][s.at(j)]+=1;
            }
        }
    }
    string ans = "";
    for(int i='a';i<='z';i++){
        int che = 10e6;
        char z = i;
        for(int j=0;j<n;j++){
            if(a.at(j).count(z)){
                che = min(che,a.at(j).at(z));
            }
            else che = 0;
        }
        for(int j=0;j<che;j++){
            ans+=z;
        }
    }
    cout << ans << endl;
}

