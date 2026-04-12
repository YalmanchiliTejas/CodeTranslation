#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    int n;
    long long int sum =0;
    int mod = 1000000007;
    cin>>n;
    vector<int> a(n);
    long int add = 0;

    for(int i=0; i<n; i++){
        cin>>a[i];
        add += a[i];
        add %= mod;
    }
    for(int i=0; i<n; i++){
        add -= a[i];
        if(add<0) add += mod;
        sum += add*a[i];
        sum%=mod;
    }

    cout<<sum<<endl;
    return 0;
}