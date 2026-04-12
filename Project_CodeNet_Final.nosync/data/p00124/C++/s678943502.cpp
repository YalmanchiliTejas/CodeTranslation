#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct T{string n; int p; };

bool operator==(const T& l, const T& r)
{
    return l.p == r.p;
}

bool operator>(const T& l, const T& r)
{
    return l.p < r.p;
}

bool operator<(const T& l, const T& r)
{
    return l.p > r.p;
}


int main()
{
    int n;
    bool fst = true;
    while(cin >> n && n) {
        if(fst) {
            fst = false;
        } else {
            cout << endl;
        }
        T v[n];
        int a, b, c;
        for(int i = 0; i < n; i++) {
            cin >> v[i].n >> a >> b >> c;
            v[i].p = a * 3 + c;
        }
        stable_sort(v, v + n);
        for(int i = 0; i < n; i++) {
            cout << v[i].n << "," << v[i].p << endl;
        }
    }
}