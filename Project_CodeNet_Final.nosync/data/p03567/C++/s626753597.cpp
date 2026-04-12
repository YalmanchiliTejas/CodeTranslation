#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ll long long


int main()
{
    string s;
    cin >> s;
    
    if (s.find("AC") != std::string::npos) {
       cout << "Yes"<< endl;
    }
    else  cout << "No"<< endl;
}