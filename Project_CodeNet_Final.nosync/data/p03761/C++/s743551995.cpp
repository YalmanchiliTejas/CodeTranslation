#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main() {
    int n;
    string ans;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> num_list(n, vector<int>(26, 0));
    vector<int> ans_list(26);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].size(); j++){
            int tmp = s[i][j] - 'a';
            num_list[i][tmp]++;
        }
    }

    for(int i=0; i<26; i++){
        int tmp=num_list[0][i];
        for(int j=1; j<n; j++){
            tmp=min(tmp, num_list[j][i]);
        }
        ans_list[i]=tmp;
    }

    for(int i=0; i<26; i++){
        while(ans_list[i]>0){
            char tmp = 'a'+i;
            cout << tmp;
            ans_list[i]--;
        }
    }
    cout << endl;

    return 0;
}