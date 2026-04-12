#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    int count = 1;
    int current_max = h[0];
    for(int i=1; i<n; i++){
        if(h[i] >= current_max){
            count += 1;
            current_max = h[i];
        }
    }
    cout << count << endl;
    return 0;
}