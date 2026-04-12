#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string s;
    int asum=0;
    int bsum=0;
    cin >> s;
    
    for(int i=0;i<=2;i++){
        if(s[i] == 'A'){
            asum+=1;
        }else{
            bsum +=1;
        }
        
    }if(asum == 3 || bsum ==3){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
}