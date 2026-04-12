#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
ll N;
ll X;

ll f(ll tmp_X, ll L){
    ll tmp_num = pow(2, L + 1) - 3;
    if(tmp_X == 0) return 0;
    if((L == 0) && (tmp_X > 0)) return 1;
    if(tmp_X <= tmp_num + 1){
        return f(tmp_X - 1, L - 1);
    }else if(tmp_X == tmp_num + 2){
        return pow(2, L);
    }else{
        return pow(2, L) + f(tmp_X - tmp_num - 2, L - 1);
    }
}
int main(){
    cin >> N >> X;
    cout << f(X, N) << endl;
}
