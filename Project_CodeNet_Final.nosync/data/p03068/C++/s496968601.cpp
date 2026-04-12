#include <iostream>
#include <string>
using namespace std;

int main(){
 string s;
 char m;
 int n,k;

 cin>>n>>s>>k;

 m=s[k-1];

for(int i=0;i<n;i++){
    if(s[i]==m){
        cout<<s[i];
    }
    else{
        cout<<"*";
    }
}

}

