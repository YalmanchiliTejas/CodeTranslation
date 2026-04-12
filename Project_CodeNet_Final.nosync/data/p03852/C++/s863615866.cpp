#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main (){
    char c;
    cin >> c;

    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }


    return 0;
}