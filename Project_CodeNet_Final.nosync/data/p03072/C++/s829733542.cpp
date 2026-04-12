#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b[100],c=1,m=0;
    cin >> a;
    cin >> b[0];
    m = b[0];
    for(int i=1;i<a;i++){
        cin >> b[i];
        if( m <= b[i] ){
            c++;
            m = b[i];
        }
    }
    cout << c;
}
