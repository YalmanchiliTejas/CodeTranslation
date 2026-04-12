#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define pb(a) push_back(a)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int multi(double p, double y, double m, double c){
    rep(i,y){
        m+=static_cast<int>(m * p);
        m-=c;
    }
    return m;
}

int single(double p, double y, double m, double c){
    double r = 0;
    rep(i,y){
        r+=static_cast<int>( m * p );
        m-=c;
    }
    return r + m;
}

int main(){
    int m;
    cin >> m;
    rep(i,m){
        double money, year, n;
        int result = 0;
        cin >> money >> year >> n;
        rep(j,n){
            double d, par, charge;
            cin >> d >> par >> charge;
            if(d) result = max(result, multi(par, year, money, charge));
            else result = max(result, single(par, year, money, charge));
        }
        cout << result << endl;
    }
}