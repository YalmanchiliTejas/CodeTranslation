#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF =1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define pb push_back
int main(){
    int n;
    cin >> n;
    int cc = 0;
    int max = 0;
    rep(i,n){
        int h;
        cin >> h;
        if(max<=h){
            max = h;
            cc++;
        }
    }
    cout<<cc<<endl;

    return 0;
}