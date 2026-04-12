#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string n;
    long k;
    cin >> n;
    long s = n.size();
    cin >> k;

    auto comb = [&](long a, long b) {
        long r = 1;
        if(a < b) return 0l;
        for(long i=0; i<b; i++)
            r *= a-i, r /= i+1;
        return r;
    };
    auto pow9 = [&](long a) -> long{
        if(a<0) return 0;
        switch(a) {
            case 0: return 1;
            case 1: return 9;
            case 2: return 81;
            case 3: return 729;
        }
        return 0;
    };

    long r = 0, t = 0;
    for(long i=0; i<s; i++) {
        if(n[i] == '0') continue;
        // 0
        r += comb(s-1-i, k-t) * pow9(k-t);
        // 1<= <n[i]
        r += comb(s-1-i, k-t-1) * (n[i]-'0' - 1) * pow9(k-1-t);
        t++;
    }
    {
        long a = 0;
        for(long i=0; i<s; i++)
            a += n[i] != '0';
        if(a == k)
            r ++ ;
    }
    cout << r << endl;
}
