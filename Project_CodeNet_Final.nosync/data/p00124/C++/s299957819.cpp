#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    int cnt = 0;
    while(cin >> n, n){
        if(cnt != 0) cout << endl;
        cnt++;
        string s[10];
        vector<int> d, e;
        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> s[i] >> a >> b >> c;
            d.push_back(3 * a + c);
        }
        e = d;
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());
        bool f[10] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i] == e[j] && f[j] == false){
                    f[j] = true;
                    cout << s[j] << "," << d[i] << endl;
                    break;
                }
            }
        }
    }
}