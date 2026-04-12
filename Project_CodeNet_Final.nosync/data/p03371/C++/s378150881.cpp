#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){

    long long int a,b,c,x,y;

    cin >> a >> b >> c >> x >> y;

    long long int m=a*x+b*y;

    long long int k=0;
    
    long long int d=0;

    while(k<2*x || k<2*y){
        long long int p=0;
        p=max(d,x-k);
        long long int q=0;
        q=max(d,y-k);
        m=min(m,a*p+b*q+2*c*k);
        int l=0;
        if(m==85002500 && l==0){
            l++;
            cout << k << endl;
        }
        k++;
    }

    cout << m << endl;


}