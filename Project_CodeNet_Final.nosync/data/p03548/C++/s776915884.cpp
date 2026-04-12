#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int A,B,C;
    cin >> A >> B >> C;
    A -= C;
    cout << A / (B+C) << endl;
}