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

#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    vector<bool> h(H,false),w(W,false);
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#'){
                h[i]=true;
                w[j]=true;
            }
        }
    }
    cout<<endl;
    
    rep(i,H){
        if(h[i]){
            rep(j,W){
                if(w[j]){
                    cout<<S[i][j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

//a=97,z=122