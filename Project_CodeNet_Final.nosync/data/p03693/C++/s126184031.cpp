#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
#include <bits/stdc++.h>
int main() {
    int a , b , c;
    cin >> a >> b >> c;
    if((a * 100 + b * 10 + c) % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
