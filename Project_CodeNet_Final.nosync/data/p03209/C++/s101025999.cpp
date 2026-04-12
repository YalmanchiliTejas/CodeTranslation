#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define dump(x) cout << #x << " = " << (x) << endl
#define chk() cout << "now" << endl;
#define SORT(c) sort((c).begin(), (c).end())
#define SORTG(c) sort((c).begin(), (c).end(), greater<int>());
#define fi first
#define se second
  
typedef pair<int,int> P;
typedef vector<int> vi;

int N,X,MAX=50;
int x[51],p[51];

int f(int N,int X) { // NバーガーのX層以下の数
    if(N==0) return 1;
    if(X==1) {
        return 0;
    }else if(1<X and X<=1+x[N-1]) {
        return f(N-1,X-1);
    }else if(X==2+x[N-1]) {
        return p[N-1]+1;
    }else if(2+x[N-1]<X and X<=2+2*x[N-1]) {
        return p[N-1]+1+f(N-1,X-2-x[N-1]);
    }else{
        return p[N];
    }
}



signed main() {
    cin>>N>>X;

    x[0]=1;
    p[0]=1;
    x[1]=5;
    p[1]=3;
    rep(i,1,N) {
        x[i+1]=x[i]*2+3;
        p[i+1]=p[i]*2+1;
    }

    cout<<f(N,X)<<endl;
    return 0;
}
    


