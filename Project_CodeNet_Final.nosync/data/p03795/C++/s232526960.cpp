#include<iostream>
#include<cstdio>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int sub = N/15;
    int ans = N*800-sub*200;
    cout << ans << endl;
    return 0;
}