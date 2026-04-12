#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;

    if(s.find("AB") != string::npos || s.find("BA") != string::npos)
        puts("Yes");
    else
        puts("No");

        return 0;
}