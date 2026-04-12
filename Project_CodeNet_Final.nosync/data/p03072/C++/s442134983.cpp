#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    int count = 0,H=0;
    for (int i = 0; i < n; i++){
        cin >> h.at(i);
        if(H <= h.at(i)){
             H = h.at(i);
             count++;
        }
        }
        cout << count << endl;
}
