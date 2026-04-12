#include<iostream>
#include<vector>
using namespace std;
#define REP(i, j) for(int i = 0; i < j; i++)

class C{
    public:
        int type, pay;
        double r;
        C(int _type, double _r, int _pay){
            type = _type;
            r = _r;
            pay = _pay;
        }
};

int main(){
    int m; cin >>m;
    REP(z, m){
        int yen, year, n; cin >>yen >>year >>n;
        vector<C> v;
        REP(i, n){
            int a, c;
            double b;
            cin >>a >>b >>c;
            v.push_back( C(a, b, c) );
        }

        int ans = 0;
        REP(i, n){
            int now = yen, tmp = 0;
            REP(j, year){
                (v[i].type? now : tmp) += (int)(now * v[i].r);
                now -= v[i].pay;
            }
            if(v[i].type == 0) now += tmp;
            ans = max(ans, now);
        }
        cout <<ans <<endl;
    }
    return 0;
}