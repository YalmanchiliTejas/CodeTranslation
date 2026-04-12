#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i]; 
    }
    int max = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(max <= h[i]){
            ans ++;
            max = h[i];
        }
    }
    cout << ans << endl;

}