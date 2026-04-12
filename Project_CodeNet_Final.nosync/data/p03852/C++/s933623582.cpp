#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>

#define rep(i, n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;

int main() {
    char ch;
    cin>>ch;
    char bo[5]={'a','e','i','o','u'};
    rep(i,5){
        if(ch==bo[i]){cout<<"vowel"<<endl;return 0;}
    }
    cout<<"consonant"<<endl;

    return 0;
}
