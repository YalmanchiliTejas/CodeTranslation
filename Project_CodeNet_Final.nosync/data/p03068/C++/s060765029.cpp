#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    char target = S[K-1];
    for(int i = 0; i < N; i++)
        if (S[i] != target)
            S[i] = '*';
    cout << S << endl;
    return 0;
}


