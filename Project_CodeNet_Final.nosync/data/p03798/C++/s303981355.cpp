//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N;
    cin>>N;
    vector<char> s(N+2);
    REP(i,N) cin>>s[i];
    s[N]=s[0];
    s[N+1]=s[1];
    
    //0:ひつじ　1:おおかみ
    const vector<pair<int,int>> a1_a2={{0,0},{0,1},{1,0},{1,1}};
    bool ans=false;
    for(auto p:a1_a2){
        vector<int> a(N+2);
        a[0]=p.first;
        a[1]=p.second;

        REP2(i,1,N+1){
            if(a[i]==0){
                if(s[i]=='o') a[i+1]=a[i-1];
                else a[i+1]=1-a[i-1];
            }else{
                if(s[i]=='x') a[i+1]=a[i-1];
                else a[i+1]=1-a[i-1];
            }
        }

        if(a[0]==a[N]&&a[1]==a[N+1]){
            REP(i,N){
                if(a[i]==0) cout<<"S";
                else cout<<"W";
            }
            cout <<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    
}