#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    long a[100010],b[100010] = {0};
    for(int i=0;i<n;++i) cin>>a[i];

    sort(a, a + n);
    b[0] = -1;
    if(n % 2==1) b[n-1] = -1;
    else b[n-1] = 1;

    int x=1;
    while(x<n-1){
        b[x] = 2;
        ++x;
        if(x>=n-1)break;
        b[x] = -2;
        ++x;
    }

    sort(b,b+n);
    long suma=0;
    for(int i=0;i<n;++i){
        suma += a[i] * b[i];
    }

    for(int i=0;i<n;++i){
        b[i] = -b[i];
    }
    sort(b,b+n);
    long sumb = 0;
    for(int i=0;i<n;++i){
        sumb += a[i] * b[i];
    }

    long sum=0;
    if(suma > sumb) sum = suma;
    else sum = sumb;

    cout << sum << endl;
}



