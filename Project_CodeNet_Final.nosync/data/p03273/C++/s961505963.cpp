#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define bitrep(X,N) for(ll X = 0; X < (1 << (N)); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end() 


using namespace std;

int main(){

    int h,w;
    cin >> h >> w;

    vector<string> s;

    rep(i,h){
        string tmps;
        cin >> tmps;
        s.pback(tmps);
    }

    vector<int> hcount;
    vector<int> wcount;

    rep(i,h) hcount.pback(0);
    rep(i,w) wcount.pback(0);

    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                hcount[i]++;
                wcount[j]++;
            }
        }
    }

    rep(i,h){
        if(hcount[i] > 0){
            rep(j,w){
                if(wcount[j] > 0){
                    cout << s[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}