#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <iomanip>


using namespace std;

int main()
{
    string s;
    cin>>s;

    for(int i=1;i<s.size();i++){
        if(s[0]!=s[i]){
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
}




