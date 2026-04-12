#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;


int main(){

    int n;
    cin >> n;

    vector<int> count(26, INT_MAX);

    rep(i, n){
        string s;
        cin >> s;

        vector<int> tmpcount(26);

        rep(j, s.size()){
            tmpcount[s[j] - 'a']++;
        }

        rep(j, 26){
            count[j] = min(count[j], tmpcount[j]);
        }
    }

    rep(i, 26){

        rep(j, count[i]){
            cout << (char)('a' + i);
        }
    }

    cout << endl;


    return 0;
}
