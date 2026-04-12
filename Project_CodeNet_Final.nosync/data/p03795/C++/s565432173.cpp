#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int times = n / 15;
    // cout << times << endl;
    cout << 800*n - (200 * (n / 15)) << endl;
    
}