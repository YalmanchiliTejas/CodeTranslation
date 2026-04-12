#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;

const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;


const int SIZE = 1e5+100;
string s;

int main(){
    cin >> s;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == 'A'){
            if(s[i+1] == 'C'){
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}