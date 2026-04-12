#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
using namespace std;


int main(void){
    int i,j;
    long long n;
    long long x,m;
    int b[100100];
    long long L1,L2;

    cin >> n >> x >> m;
    x = x%m;
    long long x0=x;
    long long x1;
    for(i=0;i<m;i++){
        b[i] = -1;
    }
    
    int k=0;
    int r;
    long long s=0;
    while(true){
    // cout << "x=" << x << ",b[x]=" << b[x] << endl;
        if(b[x] != -1){
            x1=x;
            r=b[x];
         //cout << "r=" << r << endl;
        };
        if(b[x] != -1)break;
        b[x] = k;
        s = s+x;
     //cout << x << "+" << endl;
        x = x*x%m;
        k++;
    }
    //cout << "s=" << s << endl;
    k=k-r;
    //cout << "k=" << k << endl;
    long long ans=0;

    for(i=0;i<r;i++){
        ans += x0;
        x0 = x0*x0%m;
    }

    s = s - ans;
    //cout << "s=" << s << endl;

    ans += s * ((n-r)/k);

    long long d = (n-r)%k;
    //cout << "d=" << d << endl;
    for(i=0;i<d;i++){
        ans += x1;
        x1 = x1*x1%m;
    }

    cout << ans << endl;

    return 0;
}
