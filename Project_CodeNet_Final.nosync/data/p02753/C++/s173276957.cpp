#include <iostream>
#include <vector>

#define rep(i,x) for(int i = 0; i < x; i++)
#define rrep(i,x) for(int i = 1; i <= x; i++)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using ll = long long;
using namespace std;
const int INF = 1001001001;
const ll LINF = 1002003004005006007;

int main(){
    string s; cin >> s;
    if (s[0] == 'A' and s[1] == 'A' and s[2] == 'A'){
        cout << "No" << endl;
    }else if (s[0] == 'B' and s[1] == 'B' and s[2] == 'B'){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
