#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i=0;i<N;i++){
        cin >> h.at(i);
    }
    int cnt=0;
    for (int i=1;i<N;i++){
        int flg=0;
        for (int j=0;j<i;j++){
            if(h.at(i)<h.at(j)) flg=1;
        }
        if(flg==0) cnt++;
    }
    cout << cnt+1 << endl;
    return 0;
}