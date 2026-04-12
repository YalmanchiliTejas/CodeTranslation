#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    int mount;
    int maxHeight = -1;
    for(int i = 0; i < N; i++) {
        cin >> mount;
        if (mount >= maxHeight) { 
            ans++;
            maxHeight = mount;
        }
    }
    cout << ans << endl;
}