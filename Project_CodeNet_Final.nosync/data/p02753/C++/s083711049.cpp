#include <iostream>
#include<algorithm>
using namespace std;
int main(void){
    
    string a;
    cin >> a;
    
    if(a[0] == a[1] && a[1] == a[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    
    
    
    return 0;
}