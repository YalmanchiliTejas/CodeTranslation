#include<bits/stdc++.h>

using namespace std;


int my_max(int a, int b) {
    return a > b ? a : b;
}

template <typename T>
T my_abs(T x) {
    return x < 0 ? -x : x;
}

template <typename T>
map<T, T> prime_factor(T n) {
    map<T, T> ret;
    for(T i = 2; i * i <= n; i++) {
        T tmp = 0;
        while(n % i == 0) {
            tmp++;
            n /= i;
        }
        ret[i] = tmp;
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

template <typename T>
T divisor_num(T n) {
    map<T, T> pf = prime_factor(n);
    T ret = 1;
    for(auto p : pf) {
        ret *= (p.second + 1);
    }
    return ret;
}

int main() {

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int result = 1E+9;
    int pizza = my_max(x, y);
    for(int i = 0; i <= pizza; i++) {
        int temp = (i * c * 2);
        if(x-i>0) temp += (x-i)*a;
        if(y-i>0) temp += (y-i)*b;
        if(temp < result) {
            result = temp;
        }
    }

    cout << result << endl;

    return 0;
}
