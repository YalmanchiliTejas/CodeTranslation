#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
#include<map>
#include<queue>
#include<functional>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define REV(v) reverse(v.begin(),v.end())

typedef long long ll;
typedef tuple<int,int,bool> Tb;


int atcoder(){
    //入力
    int n;
    cin >> n;
    int cnt[60][26]={};
    REP(i,n){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); ++j) cnt[i][s[j]-'a']++;
    }
    int ans[26];
    REP(i,26) ans[i]=INT_MAX;
    
    //処理
    REP(i,26){
        REP(j,n){
            ans[i] = min(cnt[j][i],ans[i]);
        }
    }
    
    string ansstr = "";
    REP(i,26){
        int tmp=ans[i];
        REP(j,tmp) ansstr += 'a'+i;
    }
    
    //出力
    cout << ansstr << ENT;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
