#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
int n;string s;int k;
cin>>n>>s>>k;
char a=s[k-1];
for(char &x:s){
    if(x!=a)x='*';
}
cout<<s;
}