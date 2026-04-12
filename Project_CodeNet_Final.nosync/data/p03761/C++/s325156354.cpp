#include <bits/stdc++.h>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int main(void){
    int n;
    cin>>n;
    vector<map<char,int>> mp;
    vector<vector<int>> ch(n,vector<int>(26));
    rep(i,0,n){
        string s;
        cin>>s;
        for(int c=0;c<s.size();c++){
            ch[i][s[c]-'a']++;
        }
    }
    string ans;
    rep(i,0,26){    // 英字26字分回す
        int minv=INF;
        rep(j,0,n){ // 文字列の数だけ
            minv=min(minv,ch[j][i]); // 各文字列の各英字の最小個数
        }
        if(minv==0)continue;
        string tmp(minv,i+'a');
        ans+=tmp; // 英字の個数分末尾に追加していく
    }
    cout<<ans<<endl;
    return 0;
}