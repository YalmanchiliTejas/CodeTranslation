//https://kyopro-friends.hatenablog.com/entry/2019/01/12/231035
//https://torus711.hatenablog.com/entry/20150423/1429794075
//勉強させて頂いた記事

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int INF=1e9+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define rv reverse

int main(){
    string K;
    int D;
    cin>>K>>D;
    int L=K.length();

    //dp[i][j][k] iは桁,jはK以下確定かどうか。もう一つ加える必要がある。
    //k各桁の総和がD倍かどうか　

    int dp[10010][2][100]={0};

    dp[0][0][0]=1;

    for(int i=0;i<L;i++){
        for(int p=0;p<D;p++){
            for(int j=0;j<2;j++){
                for(int d=0;d<=(j? 9:K[i]-'0');d++){
                    dp[i+1][j||d<K[i]-'0'][(p+d)%D]=(dp[i][j][p]+dp[i+1][j||d<K[i]-'0'][(p+d)%D])%INF;
                }
            }
        }
    }

    cout<<(dp[L][0][0]+dp[L][1][0]-1+INF)%INF<<endl;//INFを足すのはなぜだ……？



    return 0;
}

//a=97,z=122