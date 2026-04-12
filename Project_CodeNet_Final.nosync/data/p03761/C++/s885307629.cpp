#include <iostream>
#include <string>
using namespace std;

int main() {
int n,a[26];
cin>>n;
for(int &x:a){
    x=0;
}
string s;
cin>>s;
for(char x:s){
    a[x-'a']++;
}
for(int i=1;i<n;i++){
    string s;
    int b[26];
    cin>>s;
    for(int &x:b){
        x=0;
    }
    for(char x:s){
        b[x-'a']++;
    }
    for(int j=0;j<26;j++){
        a[j]=min(a[j],b[j]);
    }
}
for(int i=0;i<26;i++){
    char c='a'+i;
    for(int j=0;j<a[i];j++){
        cout<<c;
    }
}
cout<<endl;
	return 0;
}