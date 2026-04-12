#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#define loop(i,a,b) for(int i=int(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<ll> vl;

int main(){
    int x; cin >> x;
    rep(xx,x){
        int n,y;
        ll init;
        cin >> init >> y >> n;
        vl m(n);

        rep(i,n){
            int type, pay;
            double rate;
            cin >> type >> rate >> pay;
            if(type==0){
                m[i] = init;
                ll interest = 0;
                rep(j,y){
                    interest += m[i] * rate;
                    m[i] -= pay;
                }
                m[i] += interest;
            } else {
                m[i] = init;
                rep(j,y){
                    m[i] *= (rate + 1);
                    m[i] -= pay;
                }
            }
        } 
        cout << *max_element(all(m)) << endl;
    }
}