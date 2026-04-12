#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h.at(i);
    }
    int max, cnt;
    max = 0;
    cnt = 0;
    for(int i = 0; i < n; i++){
        if(h.at(i) >= max){
            max = h.at(i);
            cnt += 1;
        }
    }
    cout << cnt << endl;

}