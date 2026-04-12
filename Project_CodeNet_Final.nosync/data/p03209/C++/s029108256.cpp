#include <iostream>
using namespace std;

long long N, X;
long long p_num[51];
long long sum[51];

long long get_sum(long long n)
{
    if(sum[n] == -1) {
        if(n == 0) {
            sum[0] = 1;
        } else {
            sum[n] = 3 + 2 * get_sum(n - 1);
        }
    }
    return sum[n];
}


long long get_p(long long n)
{
    if(p_num[n] == -1) {
        if(n == 0) {
            p_num[0] = 1;
        } else {
            p_num[n] = 1 + 2 * get_p(n - 1);
        }
    }
    return p_num[n];
}

long long f(long long n, long long x)
{
    //cout << "f: (n, x) = (" << n << ", " << x << ")" << endl;
    if(n == 0) {
        return 1;
    }
    if(x == 1) {
        //cout << "A" << endl;
        return 0;
    } else if(x < get_sum(n) / 2 + 1) {
        //cout << "B" << endl;
        return f(n - 1, x - 1);
    } else if(x == get_sum(n) / 2 + 1) {
        //cout << "C" << endl;
        return get_p(n - 1) + 1;
    } else if(x < get_sum(n)) {
        //cout << "D" << endl;
        return get_p(n - 1) + f(n - 1, x - get_sum(n - 1) - 2) + 1;
    } else { // x == get_sum(n)
        //cout << "E" << endl;
        return get_p(n - 1) * 2 + 1;
    }
}

int main()
{
    cin >> N >> X;

    for(int i = 0; i <= 50; i++) {
        p_num[i] = -1;
        sum[i] = -1;
    }

    //cout << get_sum(50) << endl;
    cout << f(N, X) << endl;

    return 0;
}
