#include <iostream>
using namespace std;
int main(void){
    string s;
    getline(cin,s);
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
