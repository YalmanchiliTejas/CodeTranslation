#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int INF = 100000;
const int MAX_N = 1005;


const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int n,m;

int main(){
    int a,b;
    cin >> n >> m;
    vector<vector<int> > to(10,vector<int>(10,0));
    rep(i,m){
        cin >> a >> b;
        a--; b--;
        to[a][b] = 1;
        to[b][a] = 1;
    }

    vector<int> pr;
    int ans = 0;
    for(int i=0;i<=n-1;i++) pr.push_back(i); 
    do{
        if(pr[0]!=0) break;
        bool flag = true;
        rep(i,n-1){
            if(!to[pr[i]][pr[i+1]]) {
               flag=false;
               break;
            }
        }

       if(flag){
           ans++;
            //cout << "-------" << endl;
            //rep(i,n) cout << pr[i];
            //cout << endl;
           //cout << "ok" << endl; 
       }

    }while(next_permutation(pr.begin(),pr.end()));

    cout << ans << endl;
}