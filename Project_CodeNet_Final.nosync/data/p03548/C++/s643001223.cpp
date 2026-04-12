#include <iostream>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std; 
typedef long long int ll;

int main(){
    /*input*/
    int x,y,z;	cin >> x >> y >> z; 
    /*calculation*/
    x -= z;
    /*output*/
    cout << x/(y+z) << endl;
}
