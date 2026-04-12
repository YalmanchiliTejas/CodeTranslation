#include <iostream>
#include <string>
using namespace std;
int main(void){

    int a,b,c;
    cin >> a >> b >> c; 
    int i=0;
    a=a-c*2;
    if(a==b) {cout << "1" <<endl; return 0;}
    while(a>b){
        i++;
        a=a-(b+c);
        if(a==b){i++; break;}
    }
    
    cout << i;
    
           
     return 0;   
}
