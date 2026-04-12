#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    Rep (i, S.size()-1) {
        if (S[i] == 'A' && S[i+1] == 'C') {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}