#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    cin >> S;
    vector<map<char,int>> cnt(N);
    REP(i,N)REP(j,26)cnt[i][(char)('a'+j)] = 0;
    REP(i,N){
        for(auto s:S[i]){
            cnt[i][s]++;
        }
    }
    string ans = "";
    REP(i,26){
        int num = 100;
        REP(j,N){
            chmin(num,cnt[j][(char)('a'+i)]);
        }
        REP(j,num){
            ans = ans + (char)('a'+i);
        }
    }
    cout << ans << endl;
}