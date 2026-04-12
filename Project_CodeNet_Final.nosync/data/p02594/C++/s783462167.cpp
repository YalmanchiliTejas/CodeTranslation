#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    if(T>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
