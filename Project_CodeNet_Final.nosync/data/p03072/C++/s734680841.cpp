#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        bool higher = true;
        for(int j=0;j<i;j++){
            if(h[i] < h[j]){
                higher = false;
                break;
            }
        }
        if(higher){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}