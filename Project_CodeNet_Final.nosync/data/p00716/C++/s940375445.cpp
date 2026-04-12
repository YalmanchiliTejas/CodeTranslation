#include<iostream>

using namespace std;

template<typename T> inline void chmax(T& t, T f){if(t < f)t = f;}

int compound(int A, int year, double rate, int charge){
    int res = A;
    while(year--){
        int B = res * rate;
        res += B - charge;
    }
    return res;
}

int simple(int A, int year, double rate, int charge){
    int res1 = A, res2 = 0;
    while(year--){
        int B = res1 * rate;
        res2 += B;
        res1 -= charge;
    }
    return res1 + res2;
}

int main(){
    int m;
    cin >> m;
    while(m--){
        int init, year, n;
        cin >> init >> year >> n;
        int ans = 0;
        while(n--){
            int k, charge; double rate;
            cin >> k >> rate >> charge;
            chmax(ans, k? compound(init, year, rate, charge): simple(init, year, rate, charge));
        }
        cout << ans << '\n';
    }
    return 0;
}