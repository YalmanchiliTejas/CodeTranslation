#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> array(n),sarray(n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        ll num;
        cin >> num;
        array.at(i) = num % m;
        if(i > 0){
            sarray.at(i) = (sarray.at(i-1)+num) % m;
        }else{
            sarray.at(i) = num % m;
        }
    }
    for(int i=1;i<n;i++){
        sum += (sarray.at(i-1) * array.at(i)) % m;
    }

    cout << sum % m << endl;
    
    /*ll s = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s += (array.at(i) * array.at(j)) % 1000000007;
        }
    }
    cout << s << endl;*/
}