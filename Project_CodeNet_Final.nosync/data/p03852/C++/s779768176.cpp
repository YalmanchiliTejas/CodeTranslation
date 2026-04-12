#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s=="a" || s=="e" || s=="i" || s=="o" || s=="u"){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}

int min(int a,int b){
    if(a-b>0) return b;
    return a;
}

int max(int a,int b){
    if(a-b>0) return a;
    return b;
}

int gcd(int a,int b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}