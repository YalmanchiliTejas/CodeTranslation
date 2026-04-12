#include<iostream>
using namespace std;
int a[200000];
int main(){
    int n,index;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    index = n-1;
    while(index >= 1){
        cout << a[index] << " ";
        index -= 2;
    }
    cout << a[0] << " ";
    index = 2-n%2;
    while(index < n-1){
        cout << a[index] << " ";
        index += 2;
    }
    cout << endl;
    return 0;
}
