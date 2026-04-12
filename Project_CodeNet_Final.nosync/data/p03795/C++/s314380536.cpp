#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cctype>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    if(n>=15) cout << 800*n-(n/15)*200 << endl;
    else cout << 800*n << endl;
}
