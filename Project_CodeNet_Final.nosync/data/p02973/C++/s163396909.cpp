#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    long long c = 1;
    multiset<long long> s;
    s.insert(a[n - 1]);
    for(int i = n - 2; i >= 0; --i){
        auto now = s.upper_bound(a[i]);
        if(now == s.end()){
            c++;
            s.insert(a[i]);
        }
        else{
 
            s.erase(now);
            s.insert(a[i]);
        }
    }
    cout << c;
}