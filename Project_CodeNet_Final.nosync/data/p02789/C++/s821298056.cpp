#include <iostream>
using namespace std;


int m,n;
int main(){
    ios_base::sync_with_stdio();
    cin >> n >> m;
    if(m < n) cout << "No";
    else cout << "Yes";
}