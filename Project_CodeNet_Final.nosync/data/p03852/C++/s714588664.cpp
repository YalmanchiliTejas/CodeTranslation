#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
#define show(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    char c;
    cin >> c;
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
}