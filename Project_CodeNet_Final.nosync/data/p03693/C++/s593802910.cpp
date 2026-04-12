#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF =1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define trep(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int cc = 100 * a + 10 * b + c;
    if(cc%4==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}