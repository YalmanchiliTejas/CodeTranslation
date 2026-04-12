#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define fr(i,b,e) for(int i=(b); i<(e); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long int li;
typedef long long ll;




int main(void){
    string s(3,'0');
    cin >> s; 
    int c=count(all(s),'A');
    if(c==0 || c==3){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
