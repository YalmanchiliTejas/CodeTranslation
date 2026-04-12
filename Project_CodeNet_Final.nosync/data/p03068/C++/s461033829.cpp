#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0)
#define MAXX 1005

int n , k;
string s;

int main()
{
    _FastIO;
    cin >> n;
    cin >> s;
    cin >> k;
    char c = s[k - 1];
    for(int i = 0; i < n; i++){
        if(s[i] != c){
            cout << "*";
        }
        else
            cout << c;
    }
    cout << endl;
    return 0;
}
