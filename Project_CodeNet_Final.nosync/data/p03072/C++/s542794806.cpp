#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i=0;i<n; i++){
        cin >> h[i];
    }

    int maxH = 0, cnt = 0;
    for(int i=0; i<n;i++){
        if(maxH<=h[i]){
            cnt++;
            maxH = h[i];
        }
    }

    cout << cnt << endl;
}