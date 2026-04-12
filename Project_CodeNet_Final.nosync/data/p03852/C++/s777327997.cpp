#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    char c;
    cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
    else cout << "consonant" << endl;
}