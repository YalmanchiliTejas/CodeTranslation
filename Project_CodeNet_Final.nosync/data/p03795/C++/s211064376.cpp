#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int z;
    int sums=0;
    int& sum=sums;
    cin>>z;
    
    if(z>=15)
    {
        sum=z/15;
        cout<<z*800-sum*200<<endl;
    }else{
        cout<<z*800<<endl;        
    }
}
