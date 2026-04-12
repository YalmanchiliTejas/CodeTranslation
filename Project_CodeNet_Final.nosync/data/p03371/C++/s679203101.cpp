#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    vector<int> v;

    
    if(a + b < c * 2){
        v.push_back(a * x + b * y);
    }else{
        if(x > y){
            v.push_back(y * c * 2 + a * (x - y));
            v.push_back(c * 2 * x);
        }else if(x < y){
            v.push_back(x * c * 2 + b * (y - x));
            v.push_back(c * 2 * y);
        }else{
            v.push_back(x * c * 2);
        }
    }

    cout << *min_element(v.begin(),v.end()) << endl;
}