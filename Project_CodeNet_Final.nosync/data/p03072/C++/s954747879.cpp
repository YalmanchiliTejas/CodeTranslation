#include <bits/stdc++.h>
using namespace std;

int main() {
    //入力
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i=0; i<n; i++) {
        cin >> height.at(i);
    }

    //処理
    int count = 0;
    for (int i=0; i<n; i++) {
      	bool view = true;
        for (int j=0; j<i; j++) {
            if (height.at(j)>height.at(i)) view = false;
        }
        if (view) count++;
    }

    //出力
    cout << count << endl;

}