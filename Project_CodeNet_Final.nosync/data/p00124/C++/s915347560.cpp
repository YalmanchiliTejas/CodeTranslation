#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> d1, pair<int, int> d2){
    if(d1.first == d2.first){
        return d1.second < d2.second;
    }
    return d1.first > d2.first;
}

int main(){
    int n;
    int cnt = 0;
    while(cin >> n, n){
        if(cnt != 0) cout << endl;
        cnt++;
        string s[10];
        vector<pair<int, int> > d;
        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> s[i] >> a >> b >> c;
            d.push_back(make_pair(3 * a + c, i));
        }
        sort(d.begin(), d.end(), cmp);
        for(int i = 0; i < n; i++){
            cout << s[d[i].second] << "," << d[i].first << endl;
        }
    }
}