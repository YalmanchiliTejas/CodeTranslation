#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cfenv>
using ll = unsigned long long;
using namespace std;
int gcd(int x,int y){
    if(y==0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}
int lcm(int x,int y){
    return x/gcd(x,y)*y;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    k--;
    for(int i=0;i<n;i++){
        if(s[i]!=s[k]){
            cout<<'*';
        }else{
            cout<<s[k];
        }
    }
    cout<<endl;
}