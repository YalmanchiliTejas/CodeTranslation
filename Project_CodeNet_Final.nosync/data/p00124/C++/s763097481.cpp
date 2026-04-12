#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    for(int l = 0;;l++){
        cin >> n;
        if(n == 0) break;
        if(l != 0) cout << endl;
        vector<string> s(n);
        vector<pair<int, int> > d;
        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> s[i] >> a >> b >> c;
            d.push_back(make_pair(3 * a + c, -i));
        }
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        for(int i = 0; i < n; i++){
            cout << s[-d[i].second] << "," << d[i].first << endl;
        }
    }
}