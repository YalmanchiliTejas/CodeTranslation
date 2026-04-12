#include <iostream>
#include <string>
using namespace std;

/*
5
aba
ab
*/

int main() {
int l,n,m;
string s,t,f;
cin>>l>>s>>t;

if(s+t<=t+s){
    f=s;
    s=t;
}else{
    f=t;
}

n=f.length();
m=s.length();
t="";
for(int i=0;i*m<=l;i++){
    if((l-i*m)%n==0){
        int k=(l-i*m)/n;
        string u="";
        for(int j=0;j<k;j++){
            u+=f;
        }
        cout<<u+t<<endl;
        return 0;
    }
    t+=s;
}
	return 0;
}