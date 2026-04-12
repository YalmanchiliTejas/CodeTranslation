#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
 
int main(){
    string s;
    int flag = 0;
    string ans[] = {"Yes", "No"};
	cin>>s;
    if (s[0] == s[1]){
        if (s[1] == s[2]){
            if (s[0] == s[2]){
                flag = 1;
            }
        }
    }
	cout<<ans[flag]<<endl;
}