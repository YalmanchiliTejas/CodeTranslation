#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    int n,k;string s;
    cin>>n>>s>>k;
    char x=s[k-1];
    for(char &a:s){
        if(a!=x)a='*';
    }
    cout<<s;
}