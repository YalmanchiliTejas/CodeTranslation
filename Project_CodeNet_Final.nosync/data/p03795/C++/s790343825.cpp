#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int x=800*n; // 1食毎に800円も払う
    int y=(n/15)*200;  // 15食毎に200もらえる
    cout<<x-y<<endl;
    return 0;
}
