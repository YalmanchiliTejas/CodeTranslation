#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int x; cin>>x;
    if(x <30) cout << "No"<< endl;
    else cout << "Yes"<< endl;
}