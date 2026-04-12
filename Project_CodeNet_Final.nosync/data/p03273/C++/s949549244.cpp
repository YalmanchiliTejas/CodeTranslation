#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define repr(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define all(v) (v).begin(),(v).end()
#define chmax(a, b) a = max((a),(b))
#define chmin(a, b) a = min((a),(b))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000


typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;

bool double_check(int a){
    rep(i,inf){
        if(i*i==a){
            return true;
        }
        else if(i*i>a){
            return false;
        }
    }
}

char table[105][105];

int main(){
    int h,w;
    cin>>h>>w;
    rep(i,h)rep(j,w){
        cin>>table[i][j];
    }
    vint ansh;
    vint answ;
    rep(i,h){
        bool check=true;
        rep(j,w){
            if(table[i][j]=='#'){
                check=false;
                break;
            }
        }
        if(check==false){
            ansh.pb(i);
        }
    }
    rep(j,w){
        bool check=true;
        rep(i,h){
            if(table[i][j]=='#'){
                check=false;
                break;
            }
        }
        if(check==false){
            answ.pb(j);
        }
    }   
    for(auto i: ansh){
        for(auto j:answ){
            cout<<table[i][j];
        }
        cout<<endl;
    }
}