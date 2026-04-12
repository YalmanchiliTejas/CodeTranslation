#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
#include <numeric>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << #s << " " << s << endl

const ll mod = 1e9 + 7;
const ll inf = 1e18;

const int L_MAX = 52; // 51

void printVector(vector<ll> A){
    cout << "[vector]" << endl;
    for(int i=0; i<A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

vector<ll> LV;
vector<ll> P;

ll howManyPatti(ll level, ll eatNum){
    //cout << "how many patti " << level << " " << eatNum << endl;

    if(eatNum == 0){
        return 0;
    }

    if(level == 0){
        if(eatNum == 0){
            return 0;
        }else{
            return 1;
        }
    }

    ll center = LV[level] / 2 + 1;
    if(eatNum == 1){
        return 0;
    }else if(eatNum == LV[level]){
        return P[level];
    }
    // just center
    else if(center == eatNum){
        return P[level - 1] + 1;
    }
    // longer than center
    else if(center < eatNum){
        return P[level] - howManyPatti(level - 1, LV[level] - eatNum - 1);
    }
    // shorter than center
    else{
        return howManyPatti(level - 1, eatNum - 1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    ll N, X;
    cin >> N >> X;

    //N = 50;
    //X = 4321098765432109;
    
    // layer stats
    ll layer = 1;
    LV.push_back(1);

    FOR(i, 0, L_MAX){
        layer = 2 * layer + 3;
        LV.push_back(layer);
    }

    ll patti = 1;
    P.push_back(1);
    FOR(i, 0, L_MAX){
        patti = 2 * patti + 1;
        P.push_back(patti);
    }

    // printVector(LV);
    // printVector(P);

    p(howManyPatti(N, X));
    
    return 0;
}