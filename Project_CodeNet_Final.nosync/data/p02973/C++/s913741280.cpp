#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    int N;cin >> N;
    vector<int> A(N);
    rep(i,N)cin >> A[i];
    multiset<int> se;
    se.insert(A[0]);
    for(int i=1;i<N;i++){
        auto ite = se.lower_bound(A[i]);
        if(ite==se.begin()){
            se.insert(A[i]);
        }else{
            ite--;
            se.erase(ite);
            se.insert(A[i]);
        }
    }
    //for(auto x:se)cout << x << endl;
    cout << se.size()<< endl;
    return 0;
}