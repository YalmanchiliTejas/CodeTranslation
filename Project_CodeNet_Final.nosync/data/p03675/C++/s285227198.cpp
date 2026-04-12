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
    int n;cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<int> res(n);
    if(n%2==0){
        int suf = n/2;
        for(int i=0;0<=suf&&suf<n;i++){
            res[suf]=a[i];
            if(i%2==0){suf-=(i+1);}
            else{suf+=(i+1);}
        }
    }if(n%2==1){
        int suf = n/2;
        for(int i=0;0<=suf&&suf<n;i++){
            res[suf]=a[i];
            if(i%2==0){suf+=(i+1);}
            else{suf-=(i+1);}
        }
    }

    rep(i,n)cout << res[i] << " ";
    cout << endl;
    return 0;
}