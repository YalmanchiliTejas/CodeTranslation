#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> s >> k;
    int kk = k - 1;
    for(int i = 0; i < n; i++){
        if(s[i] == s[kk]){
            cout << s[i];
        }
        else{
            cout << "*";
        }
    }

    return 0;
}
