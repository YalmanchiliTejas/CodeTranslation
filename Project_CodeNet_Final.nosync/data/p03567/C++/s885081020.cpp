#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

int main(void) {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    string s;
    cin >> s;

    bool f1 = false;
    bool f2 = false;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            f2 = true;
        }

    }

    if(f2){
        puts("Yes");
    }else{
        puts("No");
    }
    
    return 0;
}
