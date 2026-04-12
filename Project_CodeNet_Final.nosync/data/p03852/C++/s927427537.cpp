#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << "/n"
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    char c; cin >> c;
    if(c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ){
        cout << "vowel" << endl;
    }
    else cout << "consonant" << endl;
}