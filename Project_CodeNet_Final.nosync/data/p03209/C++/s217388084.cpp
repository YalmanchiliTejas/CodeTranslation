#include <iostream>
#include <vector>

using namespace std;

vector<long long int> pnum_vec;
vector<long long int> tnum_vec;

long long int patty(const long long int n, const long long int x) {
    if(n == 0) {
        if(x == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if(x <= 1) {
        return 0;
    } else if(x < tnum_vec.at(n-1)+1) {
        return patty(n-1, x-1);
    } else if(x == tnum_vec.at(n-1)+1) {
        return pnum_vec.at(n-1);
    } else if(x == tnum_vec.at(n-1)+2) {
        return pnum_vec.at(n-1) + 1;
    } else if(x <=  2 * tnum_vec.at(n-1) + 2) {
        return pnum_vec.at(n-1) + 1 + patty(n-1, x-tnum_vec.at(n-1) - 2);
    } else {
        return 2 * pnum_vec.at(n-1) + 1;
    }
}

int main(void) {
    long long int N, X;
    cin >> N >> X;
    long long int pnum = 1; pnum_vec.push_back(pnum);
    long long int tnum = 1; tnum_vec.push_back(tnum);
    for(long long int i=1; i<=N; i++) {
        pnum = 2 * pnum + 1;
        tnum = 2 * tnum + 3;
        pnum_vec.push_back(pnum);
        tnum_vec.push_back(tnum);
    }
    cout << patty(N, X) << endl;
    return 0;
}
