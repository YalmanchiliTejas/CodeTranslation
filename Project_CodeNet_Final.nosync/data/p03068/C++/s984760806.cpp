#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,k;
    cin >>n ;
    char s[10];
    char c;
    cin >> s ;
    cin >> k;
    c=s[k-1];
    for(int i=0;i<n;i++){
        if(c!=s[i]){
            cout << "*";
        }
        else {
            cout << s[k-1];
        }
    }
    
}
