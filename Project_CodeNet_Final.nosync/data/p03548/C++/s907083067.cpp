#include<iostream>
typedef long long ll;
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int sum = y+z;
    int ans=0;
    x=x-z;
    while(x>=0){
        x=x-sum;
        if(x>=0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}