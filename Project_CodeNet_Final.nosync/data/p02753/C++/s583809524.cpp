#include<bits/stdc++.h>
using namespace std;

int main(){
    std::string a;
    cin >> a;
 
    if(a=="AAA") cout << "No" << endl;
    if(a=="ABA") cout << "Yes" << endl;
    if(a=="AAB") cout << "Yes" << endl;
    if(a=="ABB") cout << "Yes" << endl;

    if(a=="BAA") cout << "Yes" << endl;
    if(a=="BBA") cout << "Yes" << endl;
    if(a=="BAB") cout << "Yes" << endl;
    if(a=="BBB") cout << "No" << endl; 

}