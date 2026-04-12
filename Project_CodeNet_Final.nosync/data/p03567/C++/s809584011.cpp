
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <cstring>
#include <stack>
#include <cstdio>
#include <complex>
#include <iomanip>
#include <cctype>
#include <cassert>
#include <numeric>
#define rep(i,n) for(int i=0;i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define show(x) cout << #x << " = " << x << endl;

int main(){
        string s;
        cin >> s;
        rep(i,s.size()-1){
                if(s.substr(i,2)=="AC"){
                        cout << "Yes" << endl;
                        return 0;
                }
        }
        cout <<"No" << endl;
        
}