#include<bits/stdc++.h>
using namespace std;
#define long long int 
signed main(){
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int ap = a * d;
    int bp = b * e;
    int abpa = 2 * c * d;
    int abpb = 2 * c * e;
    if(d >= e)
    cout << min({ap + bp,abpa,abpb + a * (d - e)}) << endl;
    else
    cout << min({ap+bp,abpb,abpa + b * (e - d)}) << endl;
}