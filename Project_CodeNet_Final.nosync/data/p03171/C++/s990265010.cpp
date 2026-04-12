#include <iostream>
#include <algorithm>
#include <vector> //動的配列
#include <string>
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <numeric>
#include <tuple>




typedef long long ll;


using namespace std;

typedef pair<int, int> P;
#define FOR(i,a,b) for(int i=(int)(a) ; i < (int) (b) ; ++i )
#define rep(i,n) FOR(i,0,n)
#define sz(x) int(x.size())


template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

//小さい順から取り出すヒープ
//priority_queue<ll, vector<ll>, greater<ll> > pque1;


ll dp[3100][3100];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    
    
    //ある配列が与えられた時に
    //その配列から先頭を取ったときと、末尾を取った時からのスコアわかっている
    //どちらの行動を取るのが良いか
    for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len;
            
            if ((n-len)%2==0){
                //太郎の行動
                dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
            }else {
                //次郎の行動
                dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
            }
        }
    }
    
    cout<<dp[0][n]<<endl;
    
   
}
