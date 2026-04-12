#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n+1];
    for (int i=1;n>=i;i++) cin >>a[i];
    bool check=false;
    int j=n;
    while (j>=1) {
        if (check) cout<<' ';
        cout<<a[j];
        j-=2;
        check=true;
    }
    if (n%2==1) j=2;
    else j=1;
    while (n>=j) {
        cout<<' '<<a[j];
        j+=2;
    }
    cout<<endl;
}
