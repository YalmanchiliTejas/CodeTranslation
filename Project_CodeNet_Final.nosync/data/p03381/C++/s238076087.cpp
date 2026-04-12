#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
const int INF=100000000;


int main()
{
    int n,a,b;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++)cin >> x.at(i);
    y=x;
    sort(ALL(y));
    a=y[n/2];b=y[n/2-1];
    for(int i=0;i<n;i++){
        if(x[i]<=b){
            cout << a << endl;
        }else{
            cout << b << endl;
        }
    }

    return 0;
}