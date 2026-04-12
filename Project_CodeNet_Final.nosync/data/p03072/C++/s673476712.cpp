#include <bits/stdc++.h>
using namespace std;

#define f(i, q) for(int i = 0; i < q; i++)  

typedef long long ll;

vector<int> H(100);

int main() {
    int N, count = 1, flag;

    cin >> N;
    f(i, N) cin >> H.at(i);

    for(int i = 1; i < N; i++) {
        flag = 0;
        for(int j = 0; j < i; j++) {
            if(H.at(i) < H.at(j)) flag = 1;
        }
        if(flag == 0) count++;
    }

    cout << count << endl;

    return 0;
}