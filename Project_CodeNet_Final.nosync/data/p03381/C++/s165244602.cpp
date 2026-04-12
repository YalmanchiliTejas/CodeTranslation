#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin >>a[i];
    }
    int b[n];
    for (int i=0; i<n; i++){
        b[i]=a[i];
    }
    sort(a,a+n);
    int x=a[n/2-1];
    int y=a[n/2];
    for (int i=0; i<n; i++){
        if (b[i]<=x){
            cout << y <<endl;
        }
        else {
            cout << x << endl;
        }
    }
}