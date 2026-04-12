#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

vector<int> a;

ll solve(){
}

int main(void){
    int n;
    cin >> n;
    a.resize(n);
    for(auto &b: a) cin >> b;
    vector<int> b = a;
    sort(b.begin(), b.end());
    rep(i,n){
        if(a[i] <= b[n/2-1]){
            cout << b[n/2] << endl;
        }else{
            cout << b[n/2-1] << endl;
        }
    }


    return 0;
}

