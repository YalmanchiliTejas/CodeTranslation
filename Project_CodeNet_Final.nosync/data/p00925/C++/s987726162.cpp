#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include <utility>
#include<stdio.h>
#include<climits>

using namespace std;

int main(void){
    string str;
    int i,j;
    int ia,oa0,oa1;
    cin >> str;
    cin >> ia;
    oa1 = str[0]-'0';
    for(i = 1;i < str.length();i+=2){
        if(str[i] == '+'){
            oa0 = str[i+1]-'0';
            for(i += 2;i < str.length();i+=2){
                if(str[i] == '*')
                    oa0 *= str[i+1]-'0';
                else
                    break;
            }
            i -= 2;
            oa1 += oa0;
        }
        else
            oa1 *= str[i+1]-'0';
    }
    oa0 = str[0]-'0';
    for(i = 1;i < str.length();i+=2){
        if(str[i] == '+')
            oa0 += str[i+1]-'0';
        else
            oa0 *= str[i+1]-'0';
    }
    if(oa0 == ia && oa1 == ia){
        cout << "U" << endl;
    }
    else if(oa0 == ia){
        cout << "L" << endl;
    }
    else if(oa1 == ia){
        cout << "M" << endl;
    }
    else
        cout << "I" << endl;
}