#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
    int n,k;
    string s,ans = {};
    char tmp;
    cin >> n;
    cin >> s;
    cin >> k;
    tmp = s[k-1];
    for(int i = 0;i < s.size();i++){
        if(s[i] == tmp)ans += tmp;
        else ans += '*';
    }
    cout << ans << endl;
    return 0;
}
