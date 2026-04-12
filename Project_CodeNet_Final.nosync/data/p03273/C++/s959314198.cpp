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
#define pn(s) cout << (#s) << " " << (s) << endl

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void printVector(vector<ll> A){
    cout << "[vector]" << endl;
    for(int i=0; i<A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    int H, W;
    cin >> H >> W;

    string A[H];
    FOR(i, 0, H){
        cin >> A[i];
    }

    // y check
    vector<int> okY;
    FOR(i, 0, H){
        string s = A[i];
        FOR(j, 0, W){
            char c = s[j];
            if(c == '#'){
                okY.push_back(i);
                break;
            }
        }
    }

    // x check (i column)
    vector<int> okX;
    FOR(i, 0, W){
        FOR(j, 0, H){
            string s = A[j];
            if(s[i] == '#'){
                okX.push_back(i);
                break;
            }
        }
    }

    for(int y : okY){
        for(int x : okX){
            cout << A[y][x];
        }
        cout << endl;
    }
    
    return 0;
}