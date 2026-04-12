#include<iostream>
#include<string>

using namespace std;

int main(){
int a,b,c;
cin>>a>>b>>c;
int d=b*10+c;
string ret=d%4==0?"YES":"NO";
cout<<ret<<endl;
return 0;
}