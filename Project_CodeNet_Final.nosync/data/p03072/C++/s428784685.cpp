#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    vector<int> h;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        h.push_back(tmp);
    }

    int cnt = 1;
    for(int i = 1; i < h.size(); i++) {
        bool flg = true;
        for(int j = 0; j < i; j++) {
            if(h[j] > h[i]) {
                flg = false;
            }
        }
        if(flg) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}