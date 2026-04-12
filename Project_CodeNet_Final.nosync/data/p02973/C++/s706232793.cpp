//tle
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,x,n) for(int i=(x);i<(n);i++)
#define sortn(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.begin(),a.end(),greater<int>())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i,n){
        cin >> a[i];
        a[i] = -a[i];
    }
    vi p;
    int idx;

    rep(i,n){
        idx = upper_bound(p.begin(),p.end(),a[i]) -p.begin();
        if(idx != p.size()){
            p[idx] = a[i];
        }else{
            p.push_back(a[i]);
        }
    }

    cout << p.size() << endl;
    
    return 0;
}

