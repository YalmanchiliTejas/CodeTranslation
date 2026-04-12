#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 0;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
        if(ans > sum/(i+1))ans = sum/(i+1);
    }
    cout << ans << endl;
}

