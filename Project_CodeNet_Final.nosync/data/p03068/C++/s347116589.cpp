#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <map>
#include <set>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) int((x).size())
#define OUT(x) cout << (x) << endl;
typedef long long ll;
typedef pair<int, int> P;

int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    char c = s[k-1];
    string ans = "";
    for(int i = 0; i < n; i++)
    {
        if (s[i] != c) {
            ans += '*';
        }
        else
        {
            ans += s[i];
        }
    }
    OUT(ans);
}