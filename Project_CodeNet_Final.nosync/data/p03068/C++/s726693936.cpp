#include "bits/stdc++.h"
using namespace std;

#define int long long
#define MAX_N (300005)
#define INF (1LL<<60)
#define debug(x) cerr << #x <<":"<< x << endl;
#define debugVec(x) cerr << #x <<": "; for(auto p:(x)) cerr << p <<" "; cerr << endl;
#define debugVecPair(x) for(auto p:(x)) cerr << #x <<": "<< p.first <<", "<< p.second << endl;
#define debug2(x, y) cerr << #x <<" : "<< x <<", "<< #y <<" : "<< y << endl;
#define debug3(x, y, z) cerr << #x <<" : "<< x <<", "<< #y <<" : "<< y <<", "<< #z <<" : "<< z << endl;
const int MOD = (int)1e9+7;
typedef pair<int,int> P;

signed main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    char ch = S[K-1];
    string ans;
    for(int i=0; i<S.length(); i++){
        if(S[i] == ch){
            ans.push_back(S[i]);
        } else {
            ans.push_back('*');
        }
    }
    cout << ans << endl;
}