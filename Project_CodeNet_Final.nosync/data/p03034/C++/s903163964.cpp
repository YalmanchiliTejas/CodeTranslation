#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(void){
    int n;
    vector<int> s;
    long long ans = 0;
    cin >> n;
    s.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int c = 1; c < n; c++){
        int a = n-1;
        long long scr = 0;
        set<int> usd;
        for(int i=0;a>c&&c*i<n;i++){
            if(usd.find(a) != usd.end())break;
            if(usd.find(c*i) != usd.end())break;
            if(a == c*i)break;
            scr += s[a] + s[c*i];
            usd.insert(a);
            usd.insert(c*i);
            ans = max(ans, scr);
            a -= c;

        }
    }
    cout << ans << endl;
}
