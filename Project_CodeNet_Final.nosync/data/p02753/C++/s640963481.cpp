#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s; cin >> s;
  	if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
  	else cout << "Yes" << endl;

    return 0;
}
