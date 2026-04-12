#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c, x;
    while(cin >> n >> a >> b >> c >> x, n != 0){
        vector<int> y;
        for(int i=0;i<n;++i){
            int tmp;
            cin >> tmp;
            y.push_back(tmp);
        }
        int cnt = (x == y[0] ? 1 : 0), frame = 0;
        for(;frame<=10000;++frame){
            if(cnt >= n)break;
            x = (a * x + b) % c;
            if(x == y[cnt])cnt++;
        }
        cout << (cnt == n && frame <= 10000 ? frame : -1) << endl;
    }

    return 0;
}
