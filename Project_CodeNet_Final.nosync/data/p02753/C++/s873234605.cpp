#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
int main()
{
    string s;
    cin >> s;
    rep(i, 2){
        if (s[i]!=s[i+1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}