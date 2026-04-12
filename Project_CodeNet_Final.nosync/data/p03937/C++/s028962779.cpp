#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H = in(),W = in();
    vector<string> A(H);
    REP(i,H)A[i] = in<string>();
    int place = 0;
    bool over = 0;
    REP(i,H){
        while(1){
            if(A[i][place] == '#'){
                A[i][place] = '.';
            }else{
                over = 1;
            }
            if(i == H-1 && place == W-1)break;
            if(place >= W-1)break;
            if(place + 1 < W){
                if(A[i][place+1] == '.'){
                    break;
                }else{
                    place++;
                }
            }
            if(over)break;
        }
        if(over)break;
    }
    REP(i,H){
        REP(l,W){
            if(A[i][l] == '#')over = 1;
        }
    }
    cout<<fixed<<setprecision(10);
    cout << (over ? "Impossible" : "Possible") << "\n";
}