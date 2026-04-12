#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll lon(int n){
    if(n == 0) return 1;
    else return 2*lon(n-1)+3;
}

ll f(int n, ll x){
    if(n == 0 && x == 0) return 0;
    if(n == 0 && x == 1) return 1;
    if(x == 0 || x == 1) return 0;
    else if(x <= (lon(n)-1)/2) return f(n-1,x-1);
    else if(x == (lon(n)+1)/2) return f(n-1,x-2)+1;
    else if(x <= lon(n)-1) return f(n-1,lon(n-1))+f(n-1,x-lon(n-1)-2)+1;
    else return f(n-1,lon(n-1))*2+1;
}

int main(){
    int n; ll x; cin >> n >> x;
    cout << f(n,x) << endl;
}