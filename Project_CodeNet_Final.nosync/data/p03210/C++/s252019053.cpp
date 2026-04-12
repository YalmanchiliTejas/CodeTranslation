#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define print(obj) cout << obj << endl
#define scan(obj) cin >> obj

typedef long long ll;

using namespace std;

int main(void){
    int x;
    cin >> x;
    if(x == 3 || x == 5 || x == 7){
        print("YES");
        return 0;
    }

    print("NO");
}