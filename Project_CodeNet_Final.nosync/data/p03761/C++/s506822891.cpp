#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
#include <array>
#include <numeric>
#include <regex>
#include <bitset>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> p_ii;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;



int main() {
    int n;
    int cnt[30];
    for (int i = 0; i < 30; i++) {
        cnt[i]=0;
    }
    cin>>n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin>>s[i];
    }

    for (int i = 0; i <= 25; i++) {
        int ret = 1e9;
        for (int j = 0; j < n; j++) {
            int tcnt=0;
            for (int k = 0; k < s[j].size(); k++) {
                if(s[j][k]==(char)(i+'a'))tcnt++;
            }
            ret=min(ret,tcnt);
        }
        cnt[i]=ret;
    }

    for(int i = 0;i<=25;i++){
        if(cnt[i]==0)continue;
        for (int j = 0; j < cnt[i]; j++) {
            cout<<(char)(i+'a');
        }
    }
    cout<<endl;

    return 0;
}