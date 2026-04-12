#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;
int N;
int main(){
    cin >> N;
    cout << 800*N - 200*floor(N/15) << endl;
}