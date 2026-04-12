#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    string s;
    cin >> s;
    char tmp = s[0];
    bool check = false;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == tmp) continue;
        check = true;
        break;
    }
    if (check) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}