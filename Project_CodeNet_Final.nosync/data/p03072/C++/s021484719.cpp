#include <iostream>
using namespace std;
int main(void){
    int n,i,cnt=1;
    int a[20];
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    int m = a[0];
    for(i=1;i<n;i++){
        if(m<=a[i]){
            cnt++;
            m=a[i];
        }
    }
    cout << cnt;
}