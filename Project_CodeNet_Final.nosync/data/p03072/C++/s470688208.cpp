#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int n, min = 0, ans = 0;

    cin >> n;

    vector<int> h(n);

    for(int i = 0;i < n;i++){
        cin >> h[i];
    }

    for(int i = 0;i < n;i++){
        if(min <= h[i]){
            min = h[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}