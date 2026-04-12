#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    //ABC124_B
    int N;
    cin >> N;

    vector<int> mount(N);
    for(int i=0;i<N;i++){
        cin >> mount.at(i);
    }

    int high = mount.at(0);
    int ans = 1;

    for(int j=0;j<N;j++){
        if(high <= mount.at(j) && j != 0){
            high = mount.at(j);
            ans++;
        }        
    }
    cout << ans << endl;
}