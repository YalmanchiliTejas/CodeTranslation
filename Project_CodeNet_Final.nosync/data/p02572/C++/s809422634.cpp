#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int x;
    vector<long long int> a;

    for(int i = 0 ; i < n ; i++){
        cin>>x;
        a.push_back(x);
    }
    long long int output = 0;
    long long int sum = 0;

    for(int i : a){
        sum += i;
    }

    long long int mod = pow(10, 9) + 7;
    for(int i = 0 ; i < a.size() ; i++){
        sum = sum - a[i];
        // cout<<sum<<endl;
        int z = ((a[i] % mod) * (sum % mod)) % mod;
        // cout<<z<<endl;
        output = (output + z) % mod;
        // cout<<output<<endl;
    }

    cout<<output%mod;
}