#include <algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<string>
#define rep(i,n) for(int i=0; i<(int)n; i++)//n回繰り返す
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    string s;
    cin >>s;
    if(s.at(0)==s.at(1)&&s.at(0)==s.at(2)&&s.at(1)==s.at(2)){
        cout<<"No"<<endl;
     }
    else{
        cout<<"Yes"<<endl;
    }
}