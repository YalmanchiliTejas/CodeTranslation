#include <iostream>
using namespace std;
int main(void){
    string a;
    cin>>a;
    if (a[0]=='a' || a[0]=='i' || a[0]=='u' || a[0]=='e' || a[0]=='o'){
        cout<<"vowel"<<endl;
    }
    else {
        cout<<"consonant"<<endl;
    }
}
