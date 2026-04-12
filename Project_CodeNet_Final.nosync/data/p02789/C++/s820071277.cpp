#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    const char* str = n==m?"Yes":"No";
    cout << str<<endl;
    return 0;
}