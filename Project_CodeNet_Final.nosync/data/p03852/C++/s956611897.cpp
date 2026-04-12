#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(),(x).end()
#define Graph vector<vector<int>>;
#define iterG(next_v, G, v) for(auto next_v : G[v]
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c;
    string s = "aeiou";
    cin >> c;
    if(find(s.begin(), s.end(), c) != s.end()){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    
    return 0;
}

